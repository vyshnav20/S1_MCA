marks = float(input("Enter marks obtained: "))
if(marks >= 90):
    print("Marks: %.2f" % marks, "\t Grade: A")
elif(marks >= 75 and marks < 90):
    print("Marks: %.2f" % marks, "\t Grade: B")
elif(marks >= 65 and marks < 75):
    print("Marks: %.2f" % marks, "\t Grade: C")
else:
    print("Marks: %.2f" % marks, "\t Grade: F")
