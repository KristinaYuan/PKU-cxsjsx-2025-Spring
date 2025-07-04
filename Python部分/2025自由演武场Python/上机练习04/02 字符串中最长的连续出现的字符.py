s=input()
cnt={}
x=1
for i in range(len(s)):
    cnt[s[i]]=0
for i in range(1,len(s)):
    if s[i]==s[i-1]:
        x+=1
    else:
        if cnt[s[i-1]]<x:
            cnt[s[i - 1]] = x
        x=1
if cnt[s[len(s)-1]]<x:
    cnt[s[len(s)-1]]=x
mx=1
p=0
for i in range(len(s)):
    if cnt[s[i]]>mx:
        mx=cnt[s[i]]
        p=i
print(s[p],end=" ")
print(cnt[s[p]])
