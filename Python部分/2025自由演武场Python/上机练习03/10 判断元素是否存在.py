lst=input()
k=0
x=0
flag=0
for i in range(len(lst)):
    if lst[i]==',':
        flag=1
    elif flag==0:
        k*=10
        k+=int(lst[i])
    else:
        x*=10
        x+=int(lst[i])

def exist(m):
    if m==k:
        return True
    elif m<k:
        return False
    elif (m%2==1 and exist(int(m/2))) or (m%3==1 and exist(int(m/3))):
            return True
    else:
        return False

if exist(x):
    print("YES")
else:
    print("NO")
