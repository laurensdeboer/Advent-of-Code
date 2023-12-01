# ----------------------------------------------------------------------------------------
# Part One
# ----------------------------------------------------------------------------------------
def partOne() -> int:
    with open ("input.txt") as file:
        calibrationDocument = file.read().strip().split("\n")

    digitList = []
    calibrationValueSum = 0

    for line in calibrationDocument:
        for character in line:
            if character.isdigit():
                digitList.append(character)
        calibrationValueSum += int(digitList[0] + digitList[-1])
        digitList.clear()

    return calibrationValueSum

# ----------------------------------------------------------------------------------------
# Part Two
# ----------------------------------------------------------------------------------------
import re

def partTwo() -> int:
    with open ("input.txt") as file:
        calibrationDocument = file.read().strip().split("\n")

    digitList = []
    calibrationValueSum = 0
    writtenToNumber = {"one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6, "seven": 7, "eight": 8, "nine": 9}

    for line in calibrationDocument:
        writtenDigitFinder = re.findall(r"(?=(one|two|three|four|five|six|seven|eight|nine|\d))", line)

        for foundDigit in writtenDigitFinder:
            if foundDigit.isdigit():
                digitList.append(int(foundDigit))
            else:
                digitList.append(writtenToNumber[foundDigit])

        calibrationValueSum += int(str(digitList[0]) + str(digitList[-1]))
        digitList.clear()

    return calibrationValueSum

answerPartOne = partOne()
print(f"Answer part one: {answerPartOne}")
answerPartTwo = partTwo()
print(f"Answer part two: {answerPartTwo}")