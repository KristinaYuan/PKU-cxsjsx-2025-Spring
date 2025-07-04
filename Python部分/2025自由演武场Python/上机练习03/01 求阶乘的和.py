n=int(input())
ans=0
for i in range (1,n+1):
    x=1
    for j in range (1,i+1):
        x*=j
    ans+=x
print(ans)
