lst=input().split()
n,m=int(lst[0]),int(lst[1])
price={}
amount={}
for i in range(m):
    lst=input().split()
    name,price1,amount1=lst[0],int(lst[1]),int(lst[2])
    price[name]=price1
    amount[name]=amount1
ans=0
for i in range(n):
    lst=input().split()
    dish1,dish2,dish3=lst[0],lst[1],lst[2]
    if amount[dish1]>0:
        ans+=price[dish1]
        amount[dish1]-=1
    if amount[dish2]>0:
        ans+=price[dish2]
        amount[dish2]-=1
    if amount[dish3]>0:
        ans+=price[dish3]
        amount[dish3]-=1
print(ans)
