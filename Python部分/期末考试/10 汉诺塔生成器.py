def hanoi_generator(n, source, target, auxiliary):
    if n == 1:
        yield (source, target)  # 直接移动盘子
    else:
        for m in hanoi_generator(n-1,source,auxiliary,target):
            yield m
        yield (source, target)
        for m in hanoi_generator(n-1,auxiliary,target,source):
            yield m
n,k= map(int,input().split())
for move in hanoi_generator(n, 'A', 'C', 'B'):
    print(f"{move[0]}->{move[1]}")
    k -= 1
    if k == 0:
         break
