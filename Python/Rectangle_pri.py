class Rectangle:
    def __init__(self,l,b):
        self._length=l
        self._breadth=b
    def __gt__(self,a):
        area1=self._length*self._breadth
        area2=a._length*a._breadth
        if(area1>area2):
            print("Rectangle A has greater area (",area1,") than Rectangle B (",area2,")")
        elif (area1<area2):
            print("Rectangle B has greater area (",area2,") than Rectangle A (",area1,")")
        else: print("Area of Rectangle A = Area of Rectangle B =",area2)

a=Rectangle(int(input("Enter length of rectangle 1: ")),int(input("Enter widht of rectangle 1: ")))
b=Rectangle(int(input("Enter length of rectangle 2: ")),int(input("Enter widht of rectangle 2: ")))
a>b