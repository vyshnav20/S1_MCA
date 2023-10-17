a, b = map(int, input("Enter 2 numbers: ").split())
print("\t\t Before Swapping\nFirst number: ", a, "\nSecond Number: ", b)
a = a+b
b = a-b
a = a-b
print("\t\t After Swapping\nFirst number: ", a, "\nSecond Number: ", b)
