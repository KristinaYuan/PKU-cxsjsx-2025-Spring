lst=input().split()
n=int(lst[0])
p=int(lst[1])
fish=[]
for i in range(n):
    line=input().split()
    fish+=[line]
ans=0
cnt=0
for i in range(n):
    for j in range(n):
        sum=0
        for x in range(i,i+p):
            if x>=n:
                break
            for y in range(j,j+p):
                if y>=n:
                    break
                sum+=int(fish[x][y])
        if sum>ans:
            ans=sum
            cnt=1
        elif sum==ans:
            cnt+=1
print(ans,end=" ")
print(cnt)
