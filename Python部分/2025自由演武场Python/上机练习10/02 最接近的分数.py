lst=input().split()
n=int(lst[0])
a=int(lst[1])
b=int(lst[2])

def gcd(a,b):
    if a>b:
        a,b=b,a
    if b%a==0:
        return a
    return gcd(a,b%a)

p=1
q=n
while n>b/a:
    m=a*n//b
    if m*b==a*n:
        m-=1
    if gcd(m,n)==1 and m/n>p/q:
        p=m
        q=n
    n-=1
print(p,end=" ")
print(q)
