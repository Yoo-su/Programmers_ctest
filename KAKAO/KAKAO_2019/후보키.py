from itertools import combinations

def solution(relations):
    row=len(relations)
    col=len(relations[0])

    candies=[]
    for i in range(1,col+1):
        candies.extend(combinations(range(col),i))

    uniques=[]
    for candy in candies:
        tmp=[tuple([r[idx] for idx in candy]) for r in relations]
        if len(set(tmp))==row:
            uniques.append(candy)

    res=set(uniques)
    for i in range(len(uniques)):
        for j in range(i+1, len(uniques)):
            if uniques[i]==tuple(set(uniques[i])&set(uniques[j])):
                res.discard(uniques[j])

    return len(res)         
    

print(solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],
    ["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]))