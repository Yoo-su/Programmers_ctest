import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)

    while scoville[0]<K:
        try:
            tmp=heapq.heappop(scoville)+heapq.heappop(scoville)*2
            heapq.heappush(scoville,tmp)
            answer+=1
        except:
            return -1
    return answer
print(solution([1, 2, 3, 9, 10, 12],7))