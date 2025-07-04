index=input().split()
x,y=int(index[0]),int(index[1])
matrix=()
for i in range(x):
    line=input().split()
    lst=line,
    matrix=matrix+lst
for j in range(y):
    for i in range(x):
        print(matrix[i][j],end="")
        if i!=x-1:
            print(end=" ")
    if j!=y-1:
        print()
