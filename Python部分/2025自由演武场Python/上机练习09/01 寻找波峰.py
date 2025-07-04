n=int(input())
lst=input().split()
for i in range(n):
    lst[i]=int(lst[i])
ans=0
if lst[0]>lst[1]:
    ans+=1
for i in range(1,n-1):
    if lst[i]>lst[i-1] and lst[i]>lst[i+1]:
        ans+=1
if lst[n-1]>lst[n-2]:
    ans+=1
print(ans)
