# -*- coding: utf-8 -*
def test(l,i):
    if i==len(l)-1: #출력 조건: i(인덱스)가 리스트의 길이크기에 도달
        print(l)
    else:
        for j in range(i,len(l)): 
            l[i],l[j]=l[j],l[i]  #swap 해주고
            test(l,i+1)          #i(인덱스) 하나 올려서 함수호출
            l[i],l[j]=l[j],l[i]  #다음 반복을 위해 다시 원상태로 돌리는 것

test(['A','B','C'],0)



    

