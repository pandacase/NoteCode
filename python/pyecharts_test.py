import json
from pyecharts.charts import Line
from pyecharts.options import TitleOpts, LegendOpts, ToolboxOpts, VisualMapOpts, LabelOpts

# ------------------------------------------------------------------------ #


# JSON 介绍:
# json 是一种带有特定格式的字符串, 可以在各个编程语言中流通
# json 的数据格式是字典 或 嵌套了字典的列表

data = {"panda": "187", "elaina": "188"}
# 把python对象转换为json对象; json对象转python字典则使用json.loads()
json_str = json.dumps(data)  # ensure_ascii=False 则不进行转换, 此时支持中文
print(type(json_str))
print(json_str)


# ------------------------------------------------------------------------ #


# 构造折线图
line = Line()

# 给图像添加一个x轴, y轴
line.add_xaxis(["China", "America", "British", "Canada", "Japan"])
line.add_yaxis("GDP", [100, 150, 30, 60, 70])
line.add_yaxis("POP", [140, 60, 10, 40, 80], label_opts=LabelOpts(is_show=False))

# 设置全局配置项
line.set_global_opts(
    # 控制标题
    title_opts=TitleOpts(title="GDP展示", pos_left="center", pos_bottom="0%"),
    # 控制图例
    legend_opts=LegendOpts(is_show=True),
    # 工具箱
    toolbox_opts=ToolboxOpts(is_show=True),
    # 视觉映射
    visualmap_opts=VisualMapOpts(is_show=False)
)

# render方法用于生成图像
line.render()


# ------------------------------------------------------------------------ #
