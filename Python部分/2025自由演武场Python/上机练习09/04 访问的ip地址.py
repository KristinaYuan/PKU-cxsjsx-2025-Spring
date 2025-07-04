n=int(input())
ip=[]
num={}
suc={}
fail={}
for i in range(n):
    lst=input().split()
    #print(lst)
    if lst[1] in ip:
        if num[lst[1]]>int(lst[0]):
            num[lst[1]]=int(lst[0])
        if lst[2]=="1":
            suc[lst[1]]+=1
        else:
            fail[lst[1]]+=1
    else:
        suc[lst[1]]=0
        fail[lst[1]]=0
        ip+=[lst[1]]
        num[lst[1]]=int(lst[0])
        if lst[2]=="1":
            suc[lst[1]]=1
        else:
            fail[lst[1]]=1

def f(s):
    return (-suc[s],-fail[s],num[s])

ip.sort(key=f)
for i in range(len(ip)):
    print(ip[i],end=" ")
    print(suc[ip[i]],end=" ")
    print(fail[ip[i]])
