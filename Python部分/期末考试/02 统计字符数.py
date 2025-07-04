cnt=[0 for i in range(26)]
s=input()
for i in range(len(s)):
    cnt[ord(s[i])-ord("a")]+=1
mx=0
ans="a"
for i in range(26):
    if cnt[i]>mx:
        ans=chr(ord("a")+i)
        mx=cnt[i]
print(ans,mx)
