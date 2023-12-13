def getFileContents(filePath):
    with open(filePath) as file:
        return file.read().strip().split("\n")

def partOne():
    report = getFileContents("input.txt")
    result = 0
    for valueHistory in report:
        nums = [int(n) for n in valueHistory.split()]
        sequence = []

        while set(nums) != set([0]):
            sequence.append(nums[-1])
            nums = [nums[i] - nums[i-1] for i in range(1, len(nums))] 
        result += sum(sequence)

    return result

def partTwo():
    report = getFileContents("input.txt")
    result = 0
    for valueHistory in report:
        nums = [int(n) for n in valueHistory.split()]
        firstNums = []

        while set(nums) != set([0]):
            firstNums.append(nums[0])
            nums = [nums[i] - nums[i-1] for i in range(1, len(nums))]

        for i, num in enumerate(firstNums):
            result += num if i % 2 == 0 else -num

    return result

print(f"Answer part one: {partOne()}")   
print(f"Answer part two: {partTwo()}")   