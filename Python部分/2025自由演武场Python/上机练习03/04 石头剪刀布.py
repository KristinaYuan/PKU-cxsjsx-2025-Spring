lst=input().split()
N,NA,NB=int(lst[0]),int(lst[1]),int(lst[2])
a=0
b=0
MA=input().split()
MB=input().split()
x=len(MA)
y=len(MB)
for i in range (N):
    if int(MA[i%x])-int(MB[i%y]) in [2,3,-5]:
        b+=1
    elif int(MA[i%x])-int(MB[i%y]) in [-2,-3,5]:
        a+=1
if a==b:
    print("draw")
elif a>b:
    print("A")
else:
    print("B")
