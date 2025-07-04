n=int(input())
students=[]
for i in range(n):
    lst=input().split()
    students+=[lst]

def f(x):
    return (-(int(x[2])+int(x[3])+int(x[4])),-int(x[2]),-int(x[3]),x[1],x[0])

students.sort(key=f)
for i in range(n):
    print(i+1,end=" ")
    print(students[i][0])
