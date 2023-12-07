# ------------------------------ #
#       GENERAL FUNCTIONS        #
# ------------------------------ #
def getFileContents(filepath: str) -> list:
    with open(filepath) as file:
        return file.read().strip().split("\n")

def getTimeAndDistance(records):
    for line in records:
        if line.startswith("Time:"):
            timeList = [int(num) for num in line.split() if num.isdigit()]
        elif line.startswith("Distance:"):
            distList = [int(num) for num in line.split() if num.isdigit()]
    return timeList, distList

def getRaceTime(totalTime, buttonPressTime):
    return totalTime - buttonPressTime

def multiplyWaysToWin(waysToWinList):
    result = 1
    for i in waysToWinList:
        result = result * i
    return result

def getWaysToWinList(times, distances):
    waysToWinList = []
    for time, distance in zip(times, distances):
        waysToWin = 0
        for i in range(time):
            boatSpeed = i
            raceTime = getRaceTime(time, i)
            boatDistance = boatSpeed * raceTime
            if boatDistance > distance:
                waysToWin += 1
        waysToWinList.append(waysToWin)
    return waysToWinList

# ------------------------------ #
#         PART 2 FUNCTIONS       #
# ------------------------------ #
def listIntToString(list):
    intToString = [str(i) for i in list]
    return int("".join(intToString))

def fixKerning(times, distances):
    time = listIntToString(times)
    distance = listIntToString(distances)
    return time, distance

def getWaysToWin(time, distance):
    waysToWin = 0
    for i in range(time):
        boatSpeed = i
        raceTime = getRaceTime(time, i)
        boatDistance = boatSpeed * raceTime
        if boatDistance > distance:
            waysToWin += 1
    return waysToWin

# ----------------------------- #
#        PROGRAM EXECUTION      #
# ----------------------------- #
def partOne():
    records = getFileContents("input.txt")
    times, distances = getTimeAndDistance(records)
    waysToWinList = getWaysToWinList(times, distances)
    multiplied = multiplyWaysToWin(waysToWinList)
    return multiplied

def partTwo():
    records = getFileContents("input.txt")
    times, distances = getTimeAndDistance(records)
    time, distance = fixKerning(times, distances)
    waysToWin = getWaysToWin(time, distance)
    return waysToWin

print(partOne())
print(partTwo())