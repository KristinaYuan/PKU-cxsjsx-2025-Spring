def deepcopy(a):
    if isinstance(a,list):
        return [deepcopy(i) for i in a]
    if isinstance(a,tuple):
        return tuple(deepcopy(i) for i in a)
    return a
a = [1,2,[3,[4],5],(6,[7,[8],9])]
b = deepcopy(a)
print(b)
a[2][1].append(400)
a[3][1][1].append(800)
print(a)
print(b)
