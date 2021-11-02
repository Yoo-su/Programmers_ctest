from itertools import combinations

def solution(nums):
    def check(n):
        # 2부터 (x - 1)까지의 모든 수를 확인
        for i in range(2, n):
  	    # x가 해당 수로 나누어떨어지면
            if n % i == 0:
    	        return False
        return True
    
    count=0
    comb=list(combinations(nums,3))
    for item in comb:
        tmp=sum(item)
        if check(tmp):
            count+=1

    return count

print(solution([1,2,7,6,4]))