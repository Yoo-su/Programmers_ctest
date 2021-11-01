dictionary=[]
alphabets=['A','E','I','O','U']

def dfs(word):
    if len(word)==5:
        dictionary.append(word)
        return
    
    dictionary.append(word)
    
    for item in alphabets:
        dfs(word+item)


def solution(word):
    for item in alphabets:
        dfs(item)

    return dictionary.index(word)+1