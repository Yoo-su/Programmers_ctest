def solution(n,arr1,arr2):
    result=[]

    for i in range(n):
        bString=bin(arr1[i]|arr2[i])[2:].replace('1','#').replace('0',' ')
        while len(bString)<n:
            bString=" "+bString
        result.append(bString)

    return result