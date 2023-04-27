def my_levenshtein(str1, str2):
    if len(str1) != len(str2):
        return -1
    for i in range(0, len(str1)):
        if str1[i] != str2[i]:
            return i


print(my_levenshtein("GGACTGA", "GGACTGA"))
