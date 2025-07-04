def create_piece(board, pos=[0, 0]):
    return lambda m,s:isValid(board,pos,m,s)

def isValid(board,pos=[0,0],move=[0,0],step=0):
    for i in range(1,step+1):
        if not 0<=pos[1]+move[1]*i<n:
            return "Wrong move"
        elif not 0<=pos[0]+move[0]*i<n:
            return "Wrong move"
        elif board[pos[1]+move[1]*i][pos[0]+move[0]*i]=="x":
            return "Wrong move"
    pos[0]+=step*move[0]
    pos[1]+=step*move[1]
    return pos
n, start_x, start_y = map(int, input().split())

# 读取棋盘
board = []
for _ in range(n):
    row = input().strip().split()
    board.append(row)
    
# 创建棋子
piece = create_piece(board, [start_x, start_y])

# 处理移动指令
try:
    while True:
        cmd = input().strip()
        dx, dy, step = map(int, cmd.split())
        result = piece([dx, dy], step)
        print(result)
except EOFError:
    pass  # 读取到EOF时正常退出
