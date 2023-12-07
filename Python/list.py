class Lsit:
    def __init__(self):
        self.l=[]
        self.c=0
    def add(self,v):
        self.l.append(v)
        self.c+=1
    def delete(self,v):
        if v not in self.l:
            print("Value not present in list")
        else:
            self.l.remove(v)
            self.c-=1
    def display(self):
        if len(self.l)==0:
            print("list empty")
        else:
            for i in range(0,self.c):
                print(self.l[i])    

a=Lsit()
ch=0
while(ch<4):
    ch=int(input("\n 1: Add Element\n 2: Delete Element\n 3: Display\n 4: Exit\n Enter yoyr choice: "))
    if(ch==1):
        a.add(int(input("Enter value to input: ")))
    elif(ch==2):
        a.delete(int(input("Enter value to delete: ")))
    elif(ch==3):
        a.display()