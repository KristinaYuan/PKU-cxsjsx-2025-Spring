lst=input().split()
n=int(lst[0])
dif=[]
for i in range (2,n+1):
    if int(lst[i])>=int(lst[i-1]):
        d=int(lst[i])-int(lst[i-1])
    else:
        d=int(lst[i-1])-int(lst[i])
    dif+=[d]
ans=1
for i in range (1,n):
    if (i in dif)==False:
        print("Not jolly")
        ans=0
        break
if ans==1:
    print("Jolly")
