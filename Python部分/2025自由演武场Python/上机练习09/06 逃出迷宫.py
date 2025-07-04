n=int(input())
maze=[]
for i in range(n):
    line=input().split()
    maze+=[line]

def ok(r,c):
    if r==n-1 and c==n-1:
        return 1
    if r+1<n:
        if maze[r+1][c]=="0":
            if ok(r+1,c)==1:
                return 1
    if c+1<n:
        if maze[r][c+1]=="0":
            if ok(r,c+1)==1:
                return 1
    return 0

if ok(0,0)==1:
    print("Yes")
else:
    print("No")
