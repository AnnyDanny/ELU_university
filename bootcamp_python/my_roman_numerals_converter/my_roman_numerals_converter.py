def my_roman_numerals_converter(nums):
    nums_int = int(nums)
    str_sym = ""

    while (nums_int != 0):
        if nums_int >= 1000:
            quotient = int(nums_int / 1000)
            nums_int = nums_int % 1000
            str_sym = str_sym + "M" * quotient
        elif nums_int < 1000 and nums_int >= 900:
            quotient = int(nums_int / 900)
            nums_int = nums_int % 900
            str_sym = str_sym + "CM" * quotient
        elif nums_int < 900 and nums_int >= 500:
            quotient = int(nums_int / 500)
            nums_int = nums_int % 500
            str_sym = str_sym + "D" * quotient
        elif nums_int < 500 and nums_int >= 400:
            quotient = int(nums_int / 400)
            nums_int = nums_int % 400
            str_sym = str_sym + "CD" * quotient
        elif nums_int < 400 and nums_int >= 100:
            quotient = int(nums_int / 100)
            nums_int = nums_int % 100
            str_sym = str_sym + "C" * quotient
        elif nums_int < 100 and nums_int >= 90:
            quotient = int(nums_int / 90)
            nums_int = nums_int % 90
            str_sym = str_sym + "XC" * quotient
        elif nums_int < 90 and nums_int >= 50:
            quotient = int(nums_int / 50)
            nums_int = nums_int % 50
            str_sym = str_sym + "L" * quotient
        elif nums_int < 50 and nums_int >= 40:
            quotient = int(nums_int / 40)
            nums_int = nums_int % 40
            str_sym = str_sym + "XL" * quotient
        elif nums_int < 40 and nums_int >= 10:
            quotient = int(nums_int / 10)
            nums_int = nums_int % 10
            str_sym = str_sym + "X" * quotient
        elif nums_int < 10 and nums_int >= 9:
            quotient = int(nums_int / 9)
            nums_int = nums_int % 9
            str_sym = str_sym + "IX" * quotient
        elif nums_int < 9 and nums_int >= 5:
            quotient = int(nums_int / 5)
            nums_int = nums_int % 5
            str_sym = str_sym + "V" * quotient
        elif nums_int < 5 and nums_int >= 4:
            quotient = int(nums_int / 4)
            nums_int = nums_int % 4
            str_sym = str_sym + "IV" * quotient
        elif nums_int < 4 and nums_int >= 1:
            quotient = int(nums_int / 1)
            nums_int = nums_int % 1
            str_sym = str_sym + "I" * quotient
        else:
            break


    #print(str_sym)



#nums = input()
#my_roman_numerals_converter(nums)