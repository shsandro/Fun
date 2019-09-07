import sys

def main():
    nums = []           #array de números
    numsMap = {}
    solution = [0, 0]   #solução

    #constroi o array
    for line in sys.stdin:
        nums.extend(line.split(' '))

    for i in range(len(nums)):
        nums[i] = int(nums[i])

    target = nums.pop(0)

    #constroi a solução
    for i in range(len(nums)):
        val = numsMap.get(target - nums[i])

        if val:
            solution[0] = val
            solution[1] = i
            break
        else:
            numsMap.update({nums[i]: i})

    print(solution)

if __name__ == '__main__':
    main()