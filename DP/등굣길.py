from collections import defaultdict

def solution(m, n, puddles):
    mymap=[[1]*m for i in range(n)]
    for a,b in puddles:
        mymap[b-1][a-1]=0

    dic=defaultdict(int)
    dic[(0,0)]=1
    
    for i in range(1,n):
        for j in range(1,m):
            if i==1 and 1==0:
                continue
            if mymap[i][j]==0:
                dic[(i,j)]=0
            else:
                dic[(i,j)]=dic[(i-1,j)]+dic[(i,j-1)]
    print(dic)
    return dic[(n-1,m-1)]
            
print(solution(3,3,[]))