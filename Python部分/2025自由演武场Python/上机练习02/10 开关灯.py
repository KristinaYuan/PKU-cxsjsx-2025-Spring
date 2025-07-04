s=input().split()
n,m=int(s[0]),int(s[1])
print("1",end="")
for i in range (2,n+1):
    cnt=0
    for j in range(1,m+1):
        if i%j==0:
            cnt=cnt+1
    if cnt%2!=0:
        print(",%d"%i,end="")
