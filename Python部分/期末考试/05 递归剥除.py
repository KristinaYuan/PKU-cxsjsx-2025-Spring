import copy

def unwrap_single(x):
    if isinstance(x,int):
        return x
    if isinstance(x,list):
        if len(x)==1:
            return unwrap_single(x[0])
        else:
            return [unwrap_single(x[i]) for i in range(len(x))]
    if isinstance(x,tuple):
        if len(x)==1:
            return unwrap_single(x[0])
        else:
            return tuple(unwrap_single(x[i]) for i in range(len(x)))
T = int(input())
for _ in range(T):
    obj = eval(input())
    backup = copy.deepcopy(obj)
    result = unwrap_single(obj)
    assert obj == backup, "输入对象被修改"
    print(result)
