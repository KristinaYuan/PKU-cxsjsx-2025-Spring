n=int(input())
ans=2+4*n
for i in range(1,n+1):
    if i**3>n:
        break
    if n%i==0:
        for j in range(i,int(n/i+1)):
            if j**2>n/i:
                break
            if (n/i)%j==0:
                k=(n/i)/j
                a=2*(i*j+j*k+k*i)
                if a<ans:
                    ans=a
print(int(ans))
