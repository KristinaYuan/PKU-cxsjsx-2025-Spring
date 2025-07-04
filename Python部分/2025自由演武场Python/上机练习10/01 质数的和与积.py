def isPrime(n):
    for i in range(2,n):
        if n % i == 0:
            return False
        if i*i>n:
            break
    return True

s=int(input())
if s%2!=0:
    print(2*(s-2))
else:
    a=s//2
    b=s-a
    if a%2==0:
        a-=1
        b+=1
    while a>=3:
        if isPrime(a) and isPrime(b):
            print(a*b)
            break
        a-=2
        b+=2
