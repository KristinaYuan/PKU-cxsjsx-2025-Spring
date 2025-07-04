n = int(input())
info = {}
id = []
ind={}
for i in range(n):
    lst = input().split()
    id += [lst[0]]
    age = int(lst[1])
    info[id[i]] = age
    ind[id[i]]=i

def k(s):
    if info[s]>=60:
        return -info[s]*n+ind[s]
    else:
        return ind[s]


id.sort(key=k)
for i in range(len(id)):
    print(id[i])
