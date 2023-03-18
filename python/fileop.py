# import time

# ------------------------------------------------------------------------ #

# # 使用open函数 open(name, mode, encoding)Users
# # name 可以包括路径和文件名
# # mode 是打开文件的模式: 只读(r)、覆盖写入(w)、追加写入(a)等
# # encoding 是编码格式, 一般使用UTF-8

# # 一次性读取全部内容:               string = file.read()
# # 一次性读取全部内容并封装为list:    lines = file.readlines()
# # 一次只读取一行:                   line = file.readline()

# file = open("C:/Users/panda/Desktop/Desk/ML.txt", "r", encoding="UTF-8")
# print(type(file))
# file.close()

# ------------------------------------------------------------------------ #

# # with open 可以在缩进结束后自动关闭
# with open("C:/Users/panda/Desktop/Desk/ML.txt", "r", encoding="UTF-8") as file:
#     print()
#     # for循环遍历文件的每一行:
#     for line in file:
#         print(line)
#         #time.sleep(0.1)

# ------------------------------------------------------------------------ #

# # 统计file中learning的出现次数:
file = open("C:/Users/panda/Desktop/Desk/ML.txt", "r", encoding="UTF-8")
count = 0
for line in file:
    line = line.strip()
    words = line.split(" ")
    for word in words:
        if word == "learning":
            count += 1
print(f"file中'learning'出现的次数为:{count}")
file.close()

# ------------------------------------------------------------------------ #

# # 文件写入
file = open("C:/Users/panda/Desktop/Desk/test.txt", "a", encoding="UTF-8")
file.write("panda dig a hole here\n")
file.flush()  # 只有执行了flush之后才会把内存中全部内容一次性写入硬盘
file.close()  # 关闭文件之前会自动进行一次flush
file = open("C:/Users/panda/Desktop/Desk/test.txt", "r", encoding="UTF-8")
print(file.read())
