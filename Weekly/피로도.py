from itertools import permutations

def solution(k, dungeons):
    answer = []
    perm=permutations(range(len(dungeons)))
    
    for p in perm:
        tmp=k
        count=0
        
        for i in p:
            if tmp>=dungeons[i][0]:
                tmp-=dungeons[i][1]
                count+=1
        
        if count==len(dungeons):
            return count
        answer.append(count)
        
    return max(answer)