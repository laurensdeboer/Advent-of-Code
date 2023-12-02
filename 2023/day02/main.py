MAX_CUBES_RED = 12
MAX_CUBES_GREEN = 13
MAX_CUBES_BLUE = 14

def partOne():
    with open("input.txt") as file:
        games = file.read().strip().split("\n")

    sumGameID = 0
    for game in games:
        gamePossible = True
        parts = game.split(": ")
        gameID = parts[0].split()[1]
        pairs = parts[1].split("; ")
        
        for pair in pairs:
            separatedPairs = pair.split(", ")
            for seperatedPair in separatedPairs:
                cubeAmount, cubeColor = seperatedPair.split()
                if  (cubeColor == "red"   and int(cubeAmount) > MAX_CUBES_RED)   or \
                    (cubeColor == "green" and int(cubeAmount) > MAX_CUBES_GREEN) or \
                    (cubeColor == "blue"  and int(cubeAmount) > MAX_CUBES_BLUE):
                    gamePossible = False
                    break
        if gamePossible:
            sumGameID += int(gameID)

    return sumGameID

def partTwo():
    with open("input.txt") as file:
        games = file.read().strip().split("\n")

    sumGameID = 0
    for game in games:
        maxRed = 0
        maxGreen = 0
        maxBlue = 0

        parts = game.split(": ")
        pairs = parts[1].split("; ")
        
        for pair in pairs:
            separatedPairs = pair.split(", ")
            for seperatedPair in separatedPairs:
                cubeAmount, cubeColor = seperatedPair.split()
                if (cubeColor == "red" and int(cubeAmount) > maxRed):
                    maxRed = int(cubeAmount)   
                elif (cubeColor == "green" and int(cubeAmount) > maxGreen):
                    maxGreen = int(cubeAmount)
                elif (cubeColor == "blue" and int(cubeAmount) > maxBlue):
                    maxBlue = int(cubeAmount)

        sumGameID += (maxRed * maxGreen * maxBlue)
    return sumGameID
                
answerPartOne = partOne()
print(answerPartOne)
answerPartTwo = partTwo()
print(answerPartTwo)