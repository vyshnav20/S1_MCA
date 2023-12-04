from graphics import rectangle
from graphics.circle import *
from graphics.graphics3d.cuboid import area as a, peri as p
from graphics.graphics3d import sphere
l=int(input("Enter length of rectangle: "))
b=int(input("Enter width of rectangle: "))
rectangle.area(l,b)
rectangle.peri(l,b)
print("\n")
r=int(input("Enter radius of circle: "))
area(r)
peri(r)
print("\n")
l=int(input("Enter length of cuboid: "))
b=int(input("Enter width of cuboid: "))
h=int(input("Enter height of cuboid: "))
a(l,b,h)
p(l,b,h)
print("\n")
r=int(input("Enter radius of sphere: "))
sphere.area(r)
sphere.peri(r)