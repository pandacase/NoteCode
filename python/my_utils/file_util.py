def print_file_info(file_name):
    try:
        file = open(file_name, "r", encoding="UTF-8")
        print(file.read())
        file.close()
    except FileNotFoundError:
        print("FileNotFoundError")


def append_to_file(file_name, data):
    file = None
    try:
        file = open(file_name, "a", encoding="UTF-8")
        file.write("\n" + data)
        file.close()
    except FileNotFoundError:
        print("FileNotFoundError")


if __name__ == '__main__':
    append_to_file("C:/Users/panda/Desktop/Desk/test.txt", "ahhhhhh")
