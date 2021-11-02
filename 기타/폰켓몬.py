def solution(nums):
    n=len(nums)//2
    uniques=len(set(nums))

    if n>=uniques:
        return uniques
    else:
        return n


print(solution([3,3,3,2,2,2]))