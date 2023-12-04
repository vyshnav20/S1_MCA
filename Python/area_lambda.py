square=lambda x:x*x
rect=lambda a,b:a*b
triangle=lambda b,h:0.5*b*h

print("Area of square = ",square(int(input("Enter size of a side in a square: "))),"\n")
print("Area of rectangle = ",rect(int(input("Enter length of rectangle: ")),int(input("Enter width of rectangle: "))),"\n")
print("Area of rectangle = ",triangle(int(input("Enter height of triangle: ")),int(input("Enter base size of triangle: "))),"\n")
