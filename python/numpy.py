import numpy as np
import PIL as Image

# numpy中默认的数据类型是float64, 创建数组时可以使用参数"dtype="来更改
# 对于已经存在的数组则可以用.astype()方法来更改, 如 b = a.astype(int)

# 数组的创建
np.array([1, 2, 3, 4, 5])   # 一个内容为1,2,3,4,5的值的数组
np.zeros((3, 2))            # 一个3*2的全零数组(矩阵), ones则是全1的数组
np.arange(3, 5)             # 一个内容为[3, 7)递增的数组
np.linspace(0, 1, 5)        # 一个内容为[0, 1]的5等分数据点的数组
np.random.rand(2, 4)        # 一个2*4, 内容随机的数组

# 数组的运算
a = np.ones((3, 2))
b = np.ones((2, 3))
c = np.zeros((2, 3))
b + c                       # 1. 尺寸相同的数组直接进行四则运算, 尺寸不同则自动扩展后运算
a * 5                       # 2. 数组与系数运算, 这一操作成为Broadcasting
np.dot(a, b)                # 3. 可以将两个数组进行点乘运算, 语法糖为a @ b
np.sqrt(a)                  # 4. 求a数组中每个数的平方根(sin cos三角函数/ log对数)
np.power(a, 2)              # 5. 求a数组中每个数的2次方


# 数组访问/数据获取
a.sum()                     # 获得数组中全部数的总和, 参数可以放axis=0表示第0维度求和
a.min()                     # 获取a中最小的元素(最大用max())
a.argmin()                  # 获取a中最小元素的下标(最大用argmax())
a.mean()                    # 获取平均值(median()中位数, var()方差, std()标准差)

a[0, 1]                     # 访问数组中某一个元素
a[a < 3]                    # 获得所有小于3的元素a[(a>3)&(a%2==0)]
a[0, 0:2:1]                 # 取第0行中下标为[0, 2)的元素


# 应用:图像处理
im = Image.open('./memes.jpg')
im.show()                   # 图片显示
im = np.array(im)           # 图片转数组
np.shape(im)                # 显示数组的形状
