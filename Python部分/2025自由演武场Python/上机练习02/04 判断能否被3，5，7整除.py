n=int(input())
if n%105==0:
    print("3 5 7")
elif n%35==0:
    print("5 7")
elif n%21==0:
    print("3 7")
elif n%15==0:
    print("3 5")
elif n%7==0:
    print("7")
elif n%5==0:
    print("5")
elif n%3==0:
    print("3")
else:
    print("n")
