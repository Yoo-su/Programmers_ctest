def solution(N, stages):
    answer=[]
    for i in range(1,N+1):
        try:
            failP=len([x for x in stages if x==i])/len([x for x in stages if x>=i])
            answer.append((i,failP))
        except:
            answer.append((i,0))
    answer.sort(key=lambda x:(x[1],-x[0]), reverse=True)
    return [x[0] for x in answer]

print(solution(5,[2, 1, 2, 6, 2, 4, 3, 3]))