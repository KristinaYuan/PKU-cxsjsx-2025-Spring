def combine(f,g):
    return lambda x:f(g(x))
def square(x):
    return x * x
def double(x):
    return x + x
n = int(input())
f = combine(square,double)
#提示： f(x) = square(double(x))
print(f(n))
g = combine(f,double)
#提示: g(x) = f(double(x))
print(g(n))
