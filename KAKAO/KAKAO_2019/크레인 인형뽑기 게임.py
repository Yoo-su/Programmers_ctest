import sys

def solution(board, moves):
    depth=len(board)
    stack=[]
    res=0

    for x in moves:
        dep=0
        while dep<depth and board[dep][x-1]==0:
            dep+=1
        
        #모두 0이 아닌경우에 작업 처리
        if dep!=depth:
            item=board[dep][x-1]
            board[dep][x-1]=0
            if stack and stack[-1]==item:
                res+=2
                stack.pop()
            else:
                stack.append(item)

    return res

solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]],[1,5,3,5,1,2,1,4])