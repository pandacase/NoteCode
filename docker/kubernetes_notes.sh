#
# 一些初始化和状态查看
minikube start --kubernetes-version=v1.23.3 --iamge-mirror-country='cn' --memory=4096

minikube status                             # 查看集群状态
minikube node list                          # 查看节点
minikube ssh                                # 远程登录到节点上

alias kubectl="minikube kubectl --"         # 宏定义
source <(kubectl completion bash)           # 引入自动补全功能

# 运行应用
kubectl run ngx --image=nginx:alpine        # 运行一个应用，需要用--image指定一个镜像
kubectl get pod                             # 展示pod列表；pod:类似容器？但不是容器

# k8s的架构
# 集群里的计算机被称作Node，可以是实机也可以是虚机
# 少部分的Node用作"控制面"来执行集群的管理维护工作; 其他大部分节点被划归为"数据面"，用来跑业务应用
# 前者称为"Master Node"，后者称为"Worker Node"
# kubectl位于集群之外，用来操作kubernetes

minikube addons list                        # 插件列表
minikube dashboard                          # 用浏览器打开仪表盘
