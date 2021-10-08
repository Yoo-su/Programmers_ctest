def solution(scores):
    answer = ''
    avgResult=[]
    
    for i in range(len(scores)):
        tmp=[]
        for j in range(len(scores)):
            tmp.append(scores[j][i])
        #유일한 최고점 또는 최저점인 경우 제외
        if tmp.count(tmp[i])==1 and (max(tmp)==tmp[i] or min(tmp)==tmp[i]):
            tmp.remove(tmp[i])
            avg=sum(tmp)//len(tmp)
            avgResult.append(avg)
        else:
            avg=sum(tmp)//len(tmp)
            avgResult.append(avg)
            
    for item in avgResult:
        if item>=90:
            answer+='A'
        elif item>=80:
            answer+='B'
        elif item>=70:
            answer+='C'
        elif item>=50:
            answer+='D'
        else:
            answer+='F'
    
    
    return answer