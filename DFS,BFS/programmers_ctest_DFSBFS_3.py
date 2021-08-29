from typing import List

#도달 가능한 단어인지 확인해주는 함수
def ableToGo(s1:str,s2:str,length:int):
    diff=0
    for i in range(length):
        if s1[i]!=s2[i]:
            diff+=1
    
    return diff==1

def solution(begin, target, words):
    length=len(begin)
    
    words=[begin]+words   

    res=[]
    def dfs(node, step, visited:List):
        if node==target:
            res.append(step)
            return
        if node not in visited:
            visited.append(node)

        filtered=words.copy()
        filtered.remove(node)
        for item in filtered:
            if item not in visited and ableToGo(node,item,length):
                dfs(item,step+1,visited)
    
    dfs(begin,0, [])
    if not res:
        return 0
    return min(res)