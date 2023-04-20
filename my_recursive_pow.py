


def my_recursive_pow(param_1, param_2):
    if param_2 <= 0:
        return 0
    elif param_2 == 1:
        return param_1
    param_2 -= 1
    temp = my_recursive_pow(param_1, param_2)
    return temp * param_1


print(my_recursive_pow(2, 4))