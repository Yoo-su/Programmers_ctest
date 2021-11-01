def solution(numbers):
    answer = -1
    oto9=sum([x for x in range(10)])
    answer=oto9-sum(numbers)
    return answer