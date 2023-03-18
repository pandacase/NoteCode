import random
result = random.randint(1, 100)

count = 0
flag = True
while flag:
    num = int(input("请输入你的数字："))
    count += 1
    if num == result:
        print(f"you are right, {count} times you guessed totally")
        flag = False
    elif num > result:
        print("too bigger")
    else:
        print("too small")
