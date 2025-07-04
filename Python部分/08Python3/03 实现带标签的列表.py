exit = None
class TaggedList:  #元素带标签的列表
    def __init__(self,val,tag):
        self.val = val
        self.tag = tag
    def __len__(self):
        return len(self.val)
    def __contains__(self,item):
        return item in self.val
    def __str__(self):
        s=""
        for i in range(len(self)):
            s+=self.tag[i]
            s+=":"
            s+=str(self.val[i])
            s+=","
        return s
    def __getitem__(self,idx):
        if isinstance(idx,int):
            return self.val[idx]
        return self.val[self.tag.index(idx)]
    def __setitem__(self,idx,val):
        if isinstance(idx,int):
            self.val[idx]=val
        else:
            self.val[self.tag.index(idx)]=val
a = TaggedList([70,80,90,100],["语文","数学","英语","物理"])
print(len(a),78 in a, 80 in a) #>>4 False True
print(str(a)) #>>语文:70,数学:80,英语:90,物理:100,
print(a[0],a['数学']) #>>70 80   标签也可以作为下标访问元素
a[1] = a['物理'] = 85
print(a) #>>语文:70,数学:85,英语:90,物理:85,
