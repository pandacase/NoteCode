# 数据容器的通用方法
# len(container) 查询元素个数
# max/min(cntner) 查询最大/最小元素
# list/tuple/str/set(cntner) 容器转换
# sorted(cntner, reverse = bool) 容器排序(若reverse = Ture, 则反向排序; 注意:排序后变为list)


# ------------------------------------------------------------------------ #


# 数据容器-list 列表
my_list = ["panda", 187, True]
print(f"长度为3的列表的1号元素和-2号元素是否相等: {my_list[1] == my_list[-2]}")
# 可以从前往后数也可以从后往前数 ↑

# 添加元素 list.append(element)     list.extend(cntner)         list.insert(index, element)
# 删除元素 del list[index]          list.pop(index)             list.remove(element)
# 其他方法 list.clear()             list.count(element)         list.index(element)


# ------------------------------------------------------------------------ #


# 数据容器-tuple (元组, 元素不可修改)
my_tuple = tuple()  # 定义空元组
my_tuple = ("case", 317, True)
# 可用方法 tuple.index()            tuple.count()


# ------------------------------------------------------------------------ #


print()
# 数据容器-string (元素不可修改)
my_string = "pandacase"
print(f"1. the 4th letter from last of 'pandacase' is {my_string[-4]}")

# 可用方法 string.index()       string.count()    string.upper()转大写

# string.replace(x, y) 方法: 生成一个新字符串, 将x替换为y
new_my_str = my_string.replace('a', 'z')
print(f"2. after replace the 'a' with 'z' : {new_my_str}")

# string.split(str) 方法: 将string进行切, 按str来切
new_my_str = my_string.split('a')
print(f"3. after split the str with 'a' : {new_my_str}")

# string.strip(str) 方法: 去掉前后的指定str, 若未传参则去掉前后空格
new_my_str = my_string.strip('case')  # 实际上只要是任一字母的前后缀都会被剪掉
print(f"4. original str : {my_string}, strip with 'case' : {new_my_str}")


# ------------------------------------------------------------------------ #


print()
# *数据容器-序列     起始:结束:步长      default分别是：头部:尾部:1      负数则从后往前
array = my_list[::-1]
print(f"[::] : {type(array)} : {array}")


# ------------------------------------------------------------------------ #


print()
# 数据容器-set (内容无序且不支持重复数据)
my_set = set()  # 定义空集合
my_set = {"panda", "pandacda", "pase", "pananda", "pandacase", "case"}

# 添加移除 set.add(element)         set.remove(element)         set.pop()随机取出一个元素

# 集合操作 set1.difference(set2)    set1.union(set2)
new_set = my_set.difference(my_set)
new_set = my_set.union(my_set)
print(new_set)
# 集合操作set1.difference_update(set2) : set1的内容会被修改，set2不变


# ------------------------------------------------------------------------ #


# 数据容器-dict (字典，储存键值对key-value; 与集合一样，无法用index访问, 故无序)
my_dic = {}  # 定义空字典

# key和value可以是任何类型(但key不能是字典)
my_dic = {"Panda": "187317384", "Elaina": "188333262"}

# 字典嵌套示例:
score_list = {
    "dyh": {"chinese": 100, "math": 129, "english": 136},
    "lhh": {"chinese": 109, "math": 132, "english": 107},
    "kzq": {"chinese": 115, "math": 122, "english": 120}
}

# 查找:
print(f'search for dyh\'s math score : {score_list["dyh"]["math"]}')

# 新增(遇到没有的key则自动新增)/更新元素:
my_dic["lhh"] = "187482347"

# 删除元素:
the_missing_one = my_dic.pop("lhh")

# 遍历字典:
keys = my_dic.keys()
for key in keys:  # 等效于 for key in my_dict:
    print(f"check a key in my_dict : {key}")
