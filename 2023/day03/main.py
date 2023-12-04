def getFileContents(filepath: str) -> list:
    with open(filepath) as file:
        return file.read().strip().split("\n")
    
def getFileDimensions(file: str) -> int:
    return len(file), len(file[0])

def isSymbol(character: str) -> bool:
    return character not in ".0123456789\n"

def getAdjacent(engineSchematic, rows, cols, row, col) -> bool:
    for i in range(max(0, row - 1), min(rows, row + 2)):
        for j in range(max(0, col - 1), min(cols, col + 2)):
            if i != row or j != col:
                if isSymbol(engineSchematic[i][j]):
                    return True
    return False

def partOne():
    engineSchematic = getFileContents("test.txt")
    rows, cols = getFileDimensions(engineSchematic)
    digitToNumber = []
    currentRow = currentCol = partNumberSum = 0

    for line in engineSchematic:
        for character in line:
            if character.isdigit():
                digitToNumber.append(character)
                if(getAdjacent(engineSchematic, rows, cols, currentRow, currentCol)):
                    hasAdjacent = True
            if not character.isdigit() and digitToNumber:
                if hasAdjacent:
                    result = int(''.join(digitToNumber))
                    partNumberSum += result
                    hasAdjacent = False
                digitToNumber.clear()
            if currentCol < (cols - 1): 
                currentCol += 1
            else:
                currentCol = 0
        currentRow += 1

    return partNumberSum

answerPartOne = partOne()
print(f"Answer part one: {answerPartOne}")