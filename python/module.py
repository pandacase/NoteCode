# import module
# import module as 别名
# from module import 类/变量/方法
# from module import 功能名 as 别名

# py文件中含有 __all__ 变量, 一般存的是list, list中的内容是允许被使用的方法, 可以手动进行赋值修改
# from module import *      只导入module中的 __all__ 变量指定的内容, 其他东西不导入


# ------------------------------------------------------------------------ #


# 为了区分py文件之间的主从关系, 所有py文件内含一个 __name__ 变量, 运行中的主程序, 其变量值为 '__main__'
# 故在自定义的module中可以使用 if __name__ == '__main__' 来避免import后自动运行非def的代码段


# ------------------------------------------------------------------------ #


# python package:
# 一个文件夹内, 如果包含一个 __init__.py 文件, 则被标识为python package
# __int__.py 内可以对 __all__ 变量进行赋值, 以控制导入哪个包
# import package.module          注意: 此种写法,调用方法时需要用 包名.模块名.方法名 的格式
# from package import module     注意: 此种写法,调用方法只需要用 模块名.方法名 的格式
# form package.module import ... 注意: 以此类推
