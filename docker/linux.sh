# qemu gdb kernel


# 更新apt 可以解决无法下载软件的问题
    sudo apt update

# 配置c/c++环境
    sudo apt install binutils
    sudo apt install gcc/g++

# 文件操作
    mkdir       # 新建文件夹
    cp a b      # 把a复制到b(可以改后缀)
    mv a b      # 把a移动到b(可以改后缀)

# 压缩和解压
    xz       # 压缩
    xz -d    # 解压
    tar      # 压缩
    tar -xvf # 解压

# 编译(在文件目录下), -jx 是 x线程运行 用于加速
    make
    make -j4
    make -j8    


