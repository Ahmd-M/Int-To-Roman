def intToRoman(num):
    values_list = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    letters_list = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
    repetition_number = []
    roman = ""
    sum = i = 0
    while i<len(values_list):
        place_value = (num-sum) // values_list[i]
        repetition_number.append(place_value)
        for n in range(0,place_value):
            roman += letters_list[i]
        sum += place_value * values_list[i]
        i+=1
    return roman

number = 0
while not (0<number<4000):
    try:
        number = int(input("Enter  0 < integer < 4000: "))
    except:
        continue
        
roman = intToRoman(number)
print(f"{number} = {roman}")