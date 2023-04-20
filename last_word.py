import re

def last_word(param_1):
    res = re.findall(r"[\w']+", param_1)
    return res[len(res) - 1]

res_input = input()
res_output = last_word(res_input)
print(res_output)


