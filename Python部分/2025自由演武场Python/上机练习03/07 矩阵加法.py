lst=input().split()
n,m=int(lst[0]),int(lst[1])
matrix=[[0 for i in range(m)] for j in range(n)]
for i in range(n):
    line=input().split()
    for j in range(m):
        matrix[i][j]=int(line[j])
for i in range(n):
    line=input().split()
    for j in range(m):
        matrix[i][j]+=int(line[j])
for i in range(n):
    for j in range(m-1):
        print(matrix[i][j],end=' ')
    print(matrix[i][m-1])
