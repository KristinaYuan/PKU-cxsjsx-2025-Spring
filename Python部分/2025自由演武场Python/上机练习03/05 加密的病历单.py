s=input()
str1='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
str2='abcdefghijklmnopqrstuvwxyz'
lst=[]
for i in range (len(s)):
    if str1.find(s[i])!=-1:
        if str1.index(s[i])<23:
            a=str2[str1.index(s[i])+3]
            lst+=a
        else:
            a=str2[str1.index(s[i])-23]
            lst+=a
    else:
        if str2.index(s[i])<23:
            a=str1[str2.index(s[i])+3]
            lst+=a
        else:
            a=str1[str2.index(s[i])-23]
            lst+=a
for i in range (len(s)):
    print(lst[len(s)-1-i],end="")
