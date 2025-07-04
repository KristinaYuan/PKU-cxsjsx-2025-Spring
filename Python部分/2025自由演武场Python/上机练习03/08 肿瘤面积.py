n=int(input())
found=0
for i in range(n):
    lst=input().split()
    if found==0 and "0" in lst:
        x1=i
        y1=lst.index("0")
        lst.reverse()
        y2=n-1-lst.index("0")
        found=1
    elif "0" in lst:
        x2=i
ans=(x2-x1-1)*(y2-y1-1)
print(ans)
