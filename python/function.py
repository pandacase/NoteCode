def age_check(age):
    if age >= 18:
        print("你已经成年啦")
        if age >= 25:
            print("研究生毕业了你")
    elif age >= 12:
        print("你已经能玩Genshin impact了")
    else:
        print("小孩子不能玩电脑!/doge")
    return None, None


print(f"the type of the return of the function age_check is {age_check(int(input('请输入你的年龄: ')))}")
# python的函数返回值可以是多个:  x, y = age_check(18)

# ------------------------------------------------------------------------ #


# 在调用时可以指明参数进行传递, 此时可以不按照参数表的顺序进行传值
# 如果有缺省参数, 需要全部放在参数表的末尾
# 不定长的参数表:       def func(*args):    所有传入的参数都会被args接收并合并为一个tuple
# 不定长的关键字传递:   def func(**kwargs): 传入参数时需要按key-value的值那些传递, 由kwargs接收并合并为字典
def user_info(**kwargs):
    print(f"**kwargs_test: {kwargs['name']}")


user_info(name='panda', age=20, school='SYSU')


# ------------------------------------------------------------------------ #


# 函数可以作为参数传入(匿名函数), 此时传入的是运算逻辑
# lambda匿名函数:
def test_func(func):
    result = func(1, 2)
    print(f"x和y的运算结果是{result}")


def compute(x, y):
    x *= 2
    y *= 2
    return x + y


# test_func(a_computing_function_with_2args)
test_func(lambda x, y: x + y)  # 作为临时函数, 只能写一行。用处是让结构极其简单的匿名函数更快捷编写
