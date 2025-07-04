#pylint: disable = no-value-for-parameter
def accfunc(f):
    def g(g2=None):
        if g2 is None:
            return f
        return accfunc(lambda x: g2(f(x)))
    return g
def f1(x):
    return x + 1
def f2(x):
    return x * x
def f3(x):
    return x + x
def f4(x):
    return x*3
def f5(x):
    return x-4

while True:
    try:
        s = input()
        n = int(input())
        s = s.split()
        k = accfunc
        for x in s:
            k = k(eval(x))
        print(k()(n))
    except:  #读到 eof产生异常
        break
