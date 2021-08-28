from collections import defaultdict
from typing import List

#도달 가능한 단어인지 확인해주는 함수
def ableToGo(s1:str,s2:str,length:int):
    diff=0
    for i in range(length):
        if s1[i]!=s2[i]:
            diff+=1
    
    if diff==1:
        return True
    else:
        return False

def solution(begin, target, words):
    dic=defaultdict(list)
    length=len(begin)
    for item in words:
        if ableToGo(begin,item,length):
            dic[begin].append(item)
        
    for item in words:
        arr=words.copy()
        arr.remove(item)
        for item2 in arr:
            if ableToGo(item,item2,length):
                dic[item].append(item2)

    res=[]
    def dfs(node, step, visited:List):
        if node==target:
            res.append(step)
            return
        if node not in visited:
            visited.append(node)

        for item in dic[node]:
            if item not in visited:
                dfs(item,step+1,visited)
    
    dfs(begin,0, [])
    if not res:
        return 0
    return min(res)