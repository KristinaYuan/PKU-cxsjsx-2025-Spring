n=int(input())
a=1
b=1
while (a**2<n):
    if n%a==0:
        b=a
    a=a+1
x=int(2*(b+n/b))
print(x)
