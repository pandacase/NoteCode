## 
sudo apt install docker.io      # Docker的安装
sudo service docker start       # 启动docker服务
sudo usermod -aG docker ${USER} # 当前用户加入docker组 此命令运行后需要重启终端

docker version/info     # 查看版本信息/系统相关信息
docker images           # 查看本地已有的镜像
docker ps               # 查看系统运行中的所有容器
docker ps -a            # 查看已经运行完毕的所有容器
docker images           # 查看当前docker储存的所有镜像

docker pull (busybox)                       # 从外部Registry拉取一个image
    docker run (busybox) echo (hello world) # 运行busybox中的"hello world"指令
docker rmi (alpine)                         # remove images

# 隔离是如何实现的？ namespace, cgroup, chroot 三者结合实现
#    namespace:  可以创建出独立的文件系统、主机名、进程号、网络等资源空间（相当于板房
#    cgroup:     Linux Control Group 用于实现对进程的CPU、内存等资源的优先级和配额限制（相当于天花板
#    chroot:     可以更改进程的根目录，即限制访问文件系统（相当于地板

# 镜像是静态的应用容器，容器是动态的应用镜像

docker pull (alpine)
    docker run -it (alpine) sh              # -it参数表示操作环境会进入容器内部(隔离环境)
    docker run -d (nginx:alpine)            # -d:后台运行程序                
    docker run -d --name (red_srv redis)    # --name:给容器起个名字方便查看
    dokcer run -d --rm (redis)              # --rm:运行完毕后自动清除
docker exec -it red_srv sh                  # 让正在运行的容器执行另一个程序（与run的区别是不会创建新的容器
dokcer stop/start/rm (...)                  # 强制停止 / 重新启动 / 彻底清除 一个容器



#####################################################################################################################################

# 容器镜像内部的结构
#   由许多镜像层组成，每层都是只读的一组文件；相同的层可以在镜像之间共享；使用"Union FS联合文件系统"技术来合并多个层
#   使用docker pull/rmi 操作镜像时，docker会检查是否有相同的层：本地存在则不会下载/已被共享则不会删除  可以节约磁盘和网络成本
docker inspect (nginx:alpine)               # 查看一个镜像的分层信息

# Dockerfile:板房的施工图纸
    # Dockerfile.busybox
    FROM busybox                            # 选择基础镜像：关注镜像的安全和大小选择alpine、关注应用的运行稳定性选择ubuntu/debian/centOS
    CMD echo "hello world"                  # 启动容器时默认运行的命令
    COPY ./a.txt /tmp/a.txt                 # 把构建上下文里的a.txt拷贝到镜像的/tmp目录。将源码、配置等文件打包进镜像内
    RUN apt-get update \                    # 逻辑上是一行的：末尾使用续航符\，命令之间使用&&来连接
        && apt-get install -y \
            build-essential \
            curl \
        && cd /tmp \
        && curl -fSL xxx.tar.gz -o xxx.tar.gz
    # 可以把shell命令集集中写到一个脚本文件里，用COPY命令拷贝进去在用RUN来执行
    COPY setup.sh   /tmp/                   # 拷贝脚本到/tmp目录
    RUN cd /tmp && chmod +x setup.sh \      # 添加执行权限
        && ./setup.sh && rm setup.sh        # 运行脚本然后删除
    # 其他指令
    ARG IMAGE_BASE="node"                   # ARG创建的变量只在镜像构建过程中课件，容器运行时不可见
    ARG IMAGE_TAG="alpine"
    ENV PATH=$PATH:/tmp                     # ENV创建的变量不仅能在构建镜像的过程中使用，容器运行时也能以环境变量的形式被应用程序使用
    ENV DEBUG=OFF
    EXPOSE 443                              # 声明容器对外服务的端口号，对现在基于Node.js、Tomcat、Nginx、Go等开发的微服务系统来说很有用
    EXPOSE 53/upd
# .dockerignore:用于排除不需要在build的过程中打包上传的文件
    # docker ignore                         # 下面2行表示不打包上传后缀是"swp"、"sh"的文件
    *.swp
    *.sh

docker build -f (Dockerfile.busybox .)      # -f参数指定Dockerfile文件名；"."表示当前路劲；创建时尽量使用-t参数来给镜像起一个有意义的名字

# 一个完整的Dockerfile示例(注意：Dockerfile中注释应该单独成行)
    # Dockerfile
    # docker build -t ngx-app .
    # docker build -t ngx-app:1.0 .

    ARG IMAGE_BASE="nginx"
    ARG IMAGE_TAG="1.21-alpine"

    FROM ${IMAGE_BASE}:${IMAGE_TAG}

    COPY ./default.conf /etc/nginx/conf.d
    RUN cd /usr/share/nginx/html \
        && echo "hello nginx" > a.txt
    
    EXPOSE 8081 8082 8083

# 上传自己的镜像
docker login -u (pandacase)                 # 登录已经注册的账号
docker tag (ngx-app) (pandacase/ngx-app:1.0)# 把镜像改名为携带作者名称的样式
docker push (pandacase/ngx-app:1.0)         # 上传镜像到hub中
docker save/load (...)                      # 镜像归档命令，可以把镜像导出为压缩包/从压缩包导入docker；默认使用标准流，故一般会使用-o、-i参数



#####################################################################################################################################

# 容器与外界的互通
#  1. 数据拷贝
docker cp (a.txt) (ID):(/tmp)               # 把当前目录下的a.txt文件拷贝到指定容器的/tmp目录下
docker exec -it (ID) sh                     # 进入容器查看文件是否正确拷贝
docker cp (ID):(/tmp/a.txt) (.b.txt)        # 把指定容器的指定目录下的a.txt文件拷贝到主机当前的目录下，名称为b.txt
#  2. 数据共享
docker run -d --rm -v (/tmp):(/tmp) redis   # 使用-v将本机的"/tmp"目录挂载到容器里的"/tmp"里：在容器内更改文件会同步到本机去。
docker run -d --rm -v (/tmp):(/tmp):ro ...  # ":ro"表示只读
#  3. 网络互通
docker run -d --rm --net=host nginx:alpine  # 使用--net参数为容器指定网络模式：null/host/bridge；默认是bridge模式

# 分配服务器端口号
docker run -d -p 80:80  --rm nginx:alpine   
docker run -d -p 8080:80 --rm nginx:alpine  # 使用-p参数来把本机的80和8080端口分别"映射"到两个容器的80端口，不会发生冲突
curl 127.1:80 -I                            # 使用crul进行验证
