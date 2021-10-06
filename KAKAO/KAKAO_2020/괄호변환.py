import sys
from collections import deque

#올바른 괄호 문자열인지 판단하는 함수
def check(gualho):
    stack=[]
    deq=deque(list(gualho))
    while deq:
        item=deq.popleft()
        if item==')' and (not stack or stack[0]!='('):
            return False
        elif item==')' and (stack and stack[0]=='('):
            stack.pop()
        elif item=='(':
            stack.append(item)
    return True

#p를 u,v로 만드는 함수    
def makeUV(gualho):
    u,v='', ''
    for i in range(2,len(gualho)+1):
        if gualho[:i].count('(')==gualho[:i].count(')'):
            u,v = gualho[:i], gualho[i:len(gualho)]
            break

    return u,v

def solution(p):
    if not p:
        return ''
    
    if check(p):
        return p
    
    #문자열 p를 균형잡힌 괄호 문자열 u, v로 분리한다
    u,v=makeUV(p)
    res=''
    
    #u가 올바른 괄호 문자열이면 문자열 v에 대해 다시 1단계부터 수행
    if check(u):
        v=solution(v)
        res=u+v
    else:
        newu=list(u)
        res+='('
        res+=solution(v)
        res+=')'
        newu=newu[1:-1]
        for i in range(len(newu)):
            if newu[i]=='(':
                newu[i]=')'
            elif newu[i]==')':
                newu[i]='('
        newu=''.join(newu)
        res+=newu
    return res
        

        
