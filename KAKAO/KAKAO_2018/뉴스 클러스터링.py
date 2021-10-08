def solution(str1, str2):
    answer = 0
    str1=str1.upper()
    str2=str2.upper()
    list1, list2 = [], []
    gyo, hap = [], []
    
    for i in range(len(str1)-1):
        item=str1[i:i+2]
        if item.isalpha():
            list1.append(item)
    
    for i in range(len(str2)-1):
        item=str2[i:i+2]
        if item.isalpha():
            list2.append(item)
            
    set1, set2 = set(list1), set(list2)
    for item in set1:
        if item in set2:
            count1=list1.count(item)
            count2=list2.count(item)
            resCount=min(count1,count2)
            tmp=[item]*resCount
            gyo.extend(tmp)
    
    while list1:
        item=list1.pop()
        hap.append(item)
        if item in list2:
            list2.remove(item)
        
    for item in list2:
        hap.append(item)
        
    if len(gyo)==0 and len(hap)==0:
        return 65536
        
    answer=(len(gyo)/len(hap))*65536
    answer=answer//1
        
        
    return answer