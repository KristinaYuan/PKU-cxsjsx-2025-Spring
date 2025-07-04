c=input()
flag=0
for i in range(1,128,2):
    x=chr(i)
    if x==c:
        print("YES")
        flag=1
        break
if flag==0:
    print("NO")
