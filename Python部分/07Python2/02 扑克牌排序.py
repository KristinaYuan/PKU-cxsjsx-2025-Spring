def poker(s):
    ans=0
    if len(s)==3:
        ans+=10
    elif s[1]=='2':
        ans+=15
    elif s[1]=='A':
        ans+=14
    elif s[1]=='K':
        ans+=13
    elif s[1]=='Q':
        ans+=12
    elif s[1]=='J':
        ans+=11
    else:
        ans+=int(s[1])
    ans*=4
    if s[0]=='h':
        ans+=3
    elif s[0]=='s':
        ans+=2
    elif s[0]=='d':
        ans+=1
    return (-ans)

try:
    while True:
        lst = input().split()
        lst.sort(key=poker)
        if len(lst) == 0:
            print()
        else:
            print(lst[0], end="")
            for i in range(1, len(lst)):
                print(" %s" % lst[i], end="")
            print()
except EOFError:
    pass
