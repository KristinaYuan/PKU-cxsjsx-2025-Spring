lst=input().split()
n=int(lst[0])
m=int(lst[1])
cnt=[0 for i in range(m+1)]
num=[0 for i in range(n+1)]
for i in range(1,n+1):
    num[i]=int(input())
    cnt[num[i]]+=1
for i in range(1,n+1):
    if cnt[num[i]]==1:
        print("BeiJu")
    else:
        print(cnt[num[i]]-1)
