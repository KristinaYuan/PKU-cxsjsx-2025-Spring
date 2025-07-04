str1=input()
str2=input()
str='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
x= {}
a=[]
b=[]
for i in range(len(str)):
    x[str[i]]=i
    a+=[0]
    b+=[0]
for i in range(len(str1)):
    a[x[str1[i]]]+=1
for i in range(len(str2)):
    b[x[str2[i]]]+=1
a.sort()
b.sort()
ans=1
for i in range(26):
    if a[i]!=b[i]:
        ans=0
        break
if ans==1:
    print("YES")
else:
    print("NO")
