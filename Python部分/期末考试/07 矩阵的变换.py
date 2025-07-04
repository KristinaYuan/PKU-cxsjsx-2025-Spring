lst=input().split()
n,m,k=int(lst[0]),int(lst[1]),int(lst[2])
matrix=[]
for i in range(n):
    line=input().split()
    matrix+=[[int(x) for x in line]]
ans=[[0 for i in range(m)] for j in range(n)]
for i in range(n):
    for j in range(m):
        mx=matrix[i][j]
        for r in range(max(0,i-k//2),min(n,i+k//2+1)):
            for c in range(max(0,j-k//2),min(m,j+k//2+1)):
                if matrix[r][c]>mx:
                    mx=matrix[r][c]
        ans[i][j]=mx
for i in range(n):
    for j in range(m):
        print(ans[i][j],end=" ")
    print()
