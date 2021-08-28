c=[]
visited=[]
count=0
def DFS(a):
    visited[a]=True
    for i in range(0,len(c[a])):
        if visited[i]==False and c[a][i]==1:
            DFS(i)
            
def solution(n, computers):
    answer=0
    global count,c
    c=computers
    
    for i in range(0,n):
        visited.append(False)
    
    for i in range(0,len(computers)):
        if not visited[i]:
            count+=1
            DFS(i)
        
    
    answer=count
    return answer