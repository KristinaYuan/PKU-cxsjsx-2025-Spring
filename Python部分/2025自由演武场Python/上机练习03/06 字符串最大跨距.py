line=input()
cnt=0
s=""
s1=""
s2=""
for i in range(len(line)):
    if line[i]==",":
        cnt+=1
    elif cnt==0:
        s+=line[i]
    elif cnt==1:
        s1+=line[i]
    else:
        s2+=line[i]
a=s.find(s1)
b=s.rfind(s2)
if a==-1 or b==-1:
    print("-1")
elif a+len(s1)>b:
    print("-1")
else:
    print(b-a-len(s1))
