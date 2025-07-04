def value(card):
    if card[1]=="J":
        return 16
    elif card[0]=="2":
        return 15
    elif card[0]=="A":
        return 14
    elif card[0]=="K":
        return 13
    elif card[0]=="Q":
        return 12
    elif card[0]=="J":
        return 11
    elif card[0]=="T":
        return 10
    else:
        return int(card[0])

def color(card):
    if card[0]=="B" or card[0]=="L":
        return card[0]=="B"
    elif card[1]=="S":
        return 3
    elif card[1]=="H":
        return 2
    elif card[1]=="C":
        return 1
    else:
        return 0

def poker(card):
    return value(card),color(card)

try:
    while True:
        lst=input().split()
        lst.sort(key=poker,reverse=True)
        curr="X"
        for i in range(len(lst)):
            if value(lst[i])==curr:
                print("",lst[i],end="")
            elif i==0:
                curr=value(lst[i])
                print(lst[i],end="")
            else:
                curr=value(lst[i])
                print()
                print(lst[i],end="")
        print()
        print()
except EOFError:
    pass
