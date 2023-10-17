a, b, c = map(int, input("Enter 3 numbers: ").split())
if(a > b and a > c):
    print(a, " is the greates number")
elif(b > c):
    print(b, " is the greates number")
elif(c != a or c != b):
    print(c, " is the greates number")
else:
    print("Three numbers are the same")
