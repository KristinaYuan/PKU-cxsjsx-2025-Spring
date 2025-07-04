class CustomContainer:
    def __init__(self,lst):
        self.lst=lst
    def __getitem__(self, idx):
        return self.lst[idx]
    def __setitem__(self,idx,val):
        self.lst[idx]=val
    def __contains__(self, item):
        return item in self.lst
items = input().split()
operations = input().split()

container = CustomContainer(items)
output = []

i = 0
while i < len(operations):
    op = operations[i]
    if op == "set":
        index = int(operations[i+1])
        value = operations[i+2]
        container[index] = value
        i += 3
    elif op == "get":
        index = int(operations[i+1])
        output.append(str(container[index]))
        i += 2
    elif op == "in":
        value = operations[i+1]
        output.append(str(value in container))
        i += 2

print("\n".join(output))
