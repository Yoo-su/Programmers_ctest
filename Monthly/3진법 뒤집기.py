import math

def solution(n):
    ans=''
    while n>0:
        ans+=str(n%3)
        n=math.floor(n/3)
    
    res, length=0,len(ans)    
    for i in range(length):
        res+=int(ans[i])*(3**(length-(i+1)))
        
    return res
    
solution(45)