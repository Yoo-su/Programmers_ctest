from collections import deque, defaultdict

def solution(cacheSize, cities):
    q=deque()
    dic=defaultdict(bool)
    answer = 0
    
    if cacheSize==0:
        return 5*len(cities)
    
    for city in cities:
        city=city.upper()
        #큐 공간이 남았고 도시가 등록된 도시가 아니면 추가
        if len(q)<cacheSize and dic[city]!=True:
            dic[city]=True
            q.append(city)
            answer+=5
        #큐가 다 찼고 등록된 도시가 아닌경우 교체
        elif len(q)==cacheSize and dic[city]!=True:
            dic[q.popleft()]=False
            dic[city]=True
            q.append(city)
            answer+=5
        #등록된 도시면 큐 맨 뒤로 옮긴다.
        elif dic[city]==True:
            answer+=1
            q.remove(city)
            q.append(city)
            
    return answer