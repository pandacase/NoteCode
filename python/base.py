# 数据类型
box = "hello world"
box_type = type(box)
print(f"{box_type} : {box}")
#   注意：在python中，变量没有类型。赋给变量的值才有类型


# 运算符
#   // 整除，对float也生效
#   ** 取指数
#   余跟c语言相同


# 字符串格式化
phone_number = "17688054570"
time_to_call = 14
message1 = "call me %s at %s clock" % (phone_number, time_to_call)
message2 = f"call me {phone_number} at {time_to_call+1} clock"
print(message1)
print(message2)
#   %s 是字符串占位: 此外还有%d, %f
#   %5.2f 表示宽度为5, 精度为2


# ------------------------------------------------------------------------ #


# 程序遇到一个bug会停止运行 -> 对外抛出异常
# 可以对抛出的异常进行捕获并处理, 允许程序继续运行
# 异常被抛出后可以层层传递出来, 直到被捕获
# 在客户端界面表现为提示用户的输入格式有问题

try:
    file = open("C:/Users/panda/Desktop/Desk/abc.txt", "r", encoding="UTF-8")
except FileNotFoundError:
    print("the file do not exist, you can not open it in the mode 'read-only'!")
    file = open("C:/Users/panda/Desktop/Desk/abc.txt", "w", encoding="UTF-8")
# else 和 finally 可写可不写
