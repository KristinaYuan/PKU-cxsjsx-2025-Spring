n=int(input())
s=input().split()
cnt=0
for i in range(n):
    x=int(s[i])
    a=int(x/1000)
    b=int(x/100)-a*10
    c=int(x/10)-a*100-b*10
    d=x%10
    if d-a-b-c>0:
        cnt=cnt+1
print(cnt)
