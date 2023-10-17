temp = input("Enter a temperature (123 C or 123 F): ")
temp = temp.replace(' ', '')
t = float(temp[:-1])
if (temp[-1] == 'c' or temp[-1] == 'C'):
    tf = t*(9/5)+32
    print("Temperature in Fahrenheit = %.1f" % tf, " F")
elif (temp[-1] == 'f' or temp[-1] == 'F'):
    tf = (t-32)*(5/9)
    print("Temperature in Fahrenheit = %.1f" % tf, " C")
else:
    print("Invalid Temperature")
