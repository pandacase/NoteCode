class Circle():
    PI = 3.1415926  # 类属性

    def __init__(self, r) -> None:
        self.r = r  # 实例属性

    def get_area(self):
        return self.r**2 * self.PI


circle1 = Circle(3)
print(circle1.get_area())
