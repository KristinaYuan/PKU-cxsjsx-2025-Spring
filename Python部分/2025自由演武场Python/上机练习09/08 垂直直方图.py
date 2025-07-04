str="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
alphabet=[str[i] for i in range(26)]
cnt=[0 for i in range(26)]
for i in range(4):
    s=input()
    for j in range(len(s)):
        if s[j] in alphabet:
            cnt[str.index(s[j])]+=1
mx=0
for i in range(26):
    if cnt[i]>mx:
        mx=cnt[i]
graph=[[' ' for i in range(26)] for i in range(mx)]
for i in range(26):
    for j in range(mx-cnt[i],mx):
        graph[j][i]='*'
for i in range(mx):
    for j in range(25):
        print(graph[i][j],end=' ')
    print(graph[i][25])
for i in range(25):
    print(str[i],end=' ')
print("Z")
