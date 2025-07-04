m=int(input())
digits="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in range(m):
    lst=input().split(",")
    p=int(lst[0])
    n=lst[1]
    q=int(lst[2])
    ans=""
    s=0
    if n=="0":
        print("0")
        continue
    for j in range(len(n)):
        s*=p
        s+=digits.index(n[j])
    while s>0:
        ans=digits[s%q]+ans
        s//=q
    print(ans)
