from collections import deque

def solution(numbers, hand):
    answer = ''
    infoDic={}
    elements=deque([1,2,3,4,5,6,7,8,9,'*',0,'#'])
    for i in range(4):
        for j in range(3):
            infoDic[elements.popleft()]=(i,j)
        
    #거리측정 함수
    def check(p1, p2):
        return abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
        
    
    left, right = '*','#'
    for num in numbers:
        if num in [1,4,7]:
            answer+='L'
            left=num
        elif num in [2,5,8,0]:
            leftLeng, rightLeng=check(infoDic[left],infoDic[num]), check(infoDic[right],infoDic[num])
            if leftLeng<rightLeng:
                answer+='L'
                left=num
            elif leftLeng>rightLeng:
                answer+='R'
                right=num
            else:
                if hand=='left':
                    answer+='L'
                    left=num
                else:
                    answer+='R'
                    right=num
        else:
            answer+='R'
            right=num

    return answer

print(solution([5,2,8,0],"right"))