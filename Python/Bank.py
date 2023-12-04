class Bank:
    def __init__(self,n,name,type):
        self.number=n
        self.name=name
        self.type=type
        self.balance=0
    
    def deposit(self,amount):
        self.balance+=amount
        print(amount," Deposited!!!\nBalance = ",self.balance)
    
    def withdraw(self,amount):
        if(amount>self.balance):
            print("Insufficient amount!!! Cannot withdraw!!!")
        else:
            self.balance-=amount
            print(amount," Withdrawn!!!\nBalance = ",self.balance)

    def details(self):
        print("Account Number: ",self.number)
        print("Account Name: ",self.name)
        print("Account Type: ",self.type)
        print("Balance Amount: ",self.balance)

n=int(input("Enter account number: "))
name=input("Enter name: ")
type=input("Enter account type: ")
b=Bank(n,name,type)
ch=1
while(ch<4):
    ch=int(input("----------------\n1: Account Details\n2:Withdraw\n3:Deposit\n4:Exit\n----------------\nEnter your choice: "))
    if(ch==1):
        b.details()
    elif(ch==2):
        b.withdraw(int(input("Enter amount to withdraw: ")))
    elif(ch==3):
        b.deposit(int(input("Enter amount to deposit: ")))
