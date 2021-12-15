def solution(jobs):
    answer, prevEnd, length=0,0,len(jobs)
    jobs.sort(key=lambda x:x[1])
    
    while jobs:
        for i in range(len(jobs)):
            if prevEnd>=jobs[i][0]:
                answer+=(prevEnd-jobs[i][0])+jobs[i][1]
                prevEnd+=jobs[i][1]
                jobs.pop(i)
                break
            if i==len(jobs)-1:
                prevEnd+=1
                
    return answer//length