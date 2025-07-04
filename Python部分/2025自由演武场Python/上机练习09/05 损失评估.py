lst=input().split()
N=int(lst[0])
M=int(lst[1])
loss=[[0 for i in range(M+2)] for i in range(N+2)]
explode=[[0 for i in range(M+2)] for i in range(N+2)]
money=[[0 for i in range(M+2)] for i in range(N+2)]
for i in range(1,N+1):
    lst=input().split()
    for j in range(1,M+1):
        tmp=lst[j-1].split(':')
        if tmp[0]=="X":
            explode[i][j]=1
            loss[i][j]=1
        money[i][j]=int(tmp[1])
for i in range(1,N+1):
    for j in range(1,M+1):
        if explode[i-1][j]==1 or explode[i+1][j]==1 or explode[i][j-1]==1 or explode[i][j+1]==1:
            loss[i][j]=1
        if explode[i][j]==1:
            x=money[i-1][j]+money[i+1][j]+money[i][j-1]+money[i][j+1]+money[i][j]
            print("(",end="")
            print(i,end=",")
            print(j,end="):")
            print(x)
sum=0
for i in range(1,N+1):
    for j in range(1,M+1):
        if loss[i][j]==1:
            sum+=money[i][j]
print(sum)
