n=int(input())
Haab=['pop','no','zip','zotz','tzec','xul','yoxkin','mol','chen','yax','zac','ceh','mac','kankin','muan','pax','koyab','cumhu','uayet']
Tzolkin=['imix','ik','akbal','kan','chicchan','cimi','manik','lamat','muluk','ok','chuen','eb','ben','ix','mem','cib','caban','eznab','canac','ahau']
print(n)
for k in range(n):
    days=0
    lst=input().split()
    d=int(float(lst[0]))
    m=Haab.index(lst[1])+1
    y=int(lst[2])
    days+=y*365+(m-1)*20+d
    print(1+days%13,end=" ")
    print(Tzolkin[days%20],end=" ")
    print(int(days/260))
