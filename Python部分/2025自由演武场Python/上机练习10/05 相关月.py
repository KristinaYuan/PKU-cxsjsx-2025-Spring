def isRunYear(y):
    if y%4!=0:
        return False
    if y%100!=0:
        return True
    if y%400==0:
        return True
    return False


days=[0,31,28,31,30,31,30,31,31,30,31,30,31]

def daysOfMonth(y,m):
    if m==2:
        return days[2]+isRunYear(y)
    return days[m]

n=int(input())
for k in range(n):
    lst=input().split()
    year=int(lst[0])
    month1,month2=min(int(lst[1]),int(lst[2])),max(int(lst[1]),int(lst[2]))
    d=0
    for i in range(month1,month2):
        d+=daysOfMonth(year,i)
    if d%7==0:
        print("YES")
    else:
        print("NO")
