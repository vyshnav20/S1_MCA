class Rectangle:
    def __init__(self,a,b):
        self.a=a
        self.b=b
    def area(self):
        return (self.a*self.b)
    
    def peri(self):
        return (2*(self.a+self.b))




r1=Rectangle(int(input("Enter length of rectangle 1: ")),int(input("Enter widht of rectangle 1: ")))
r2=Rectangle(int(input("Enter length of rectangle 2: ")),int(input("Enter widht of rectangle 2: ")))

if(r1.area()>r2.area()):
    print("Area of rectangle 1: ",r1.area(),"> Area of rectangle 2: ",r2.area())
elif(r1.area()<r2.area()):
    print("Area of rectangle 1: ",r1.area(),"< Area of rectangle 2: ",r2.area())
else:
    print("Area of rectangle 1 = Area of rectangle 2 = ",r2.area())

if(r1.peri()>r2.peri()):
    print("Perimeter of rectangle 1: ",r1.peri(),"> Perimeter of rectangle 2: ",r2.peri())
elif(r1.peri()<r2.peri()):
    print("Perimeter of rectangle 1: ",r1.peri(),"< Perimeter of rectangle 2: ",r2.peri())
else:
    print("Perimeter of rectangle 1 = Perimeter of rectangle 2 = ",r2.peri())    