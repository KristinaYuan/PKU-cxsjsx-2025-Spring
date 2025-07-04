n=int(input())
ans=0
a,b=2,1
for i in range (n):
    ans+=a/b
    a,b=a+b,a
print("%.4f"%ans)
