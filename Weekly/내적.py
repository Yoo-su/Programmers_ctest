def solution(a, b):
    answer=0
    leng=len(a)

    for i in range(leng):
        answer+=a[i]*b[i]
    return answer