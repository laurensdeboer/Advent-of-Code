def getFileContents(filepath: str) -> list:
    with open(filepath) as file:
        return file.read().strip().split("\n")
    
def splitScratchcard(scratchcard: str) -> str:
    numbers = scratchcard.split(": ")[1]
    winningNumbers, yourNumbers = numbers.split(" | ")
    return winningNumbers, yourNumbers

def calculateScore(matchingNumbers) -> int:
    return 0 if not matchingNumbers else pow(2, len(matchingNumbers) - 1)

def partOne() -> int:
    scratchcards = getFileContents("input.txt")
    answer = 0

    for scratchcard in scratchcards:
        winningNumbers, yourNumbers = splitScratchcard(scratchcard)
        winningNumbers = {int(num) for num in winningNumbers.split()}
        yourNumbers = {int(num) for num in yourNumbers.split()}
        matchingNumbers = winningNumbers.intersection(yourNumbers)
        answer += calculateScore(matchingNumbers)
    
    return answer

def splitScratchcardTwo(scratchcard: str) -> str:
    cardNumber, scratchcardNumbers = scratchcard.split(": ")
    cardNumber = cardNumber.split()[1]
    winningNumbers, yourNumbers = scratchcardNumbers.split(" | ")
    return cardNumber, winningNumbers, yourNumbers

def fillCardList(cardList, cardNumber, matchingNumbersAmt):
    for i in range(matchingNumbersAmt):
        cardList[int(cardNumber) + i] += (cardList[int(cardNumber) - 1])

def partTwo() -> int:
    scratchcards = getFileContents("input.txt")
    cardList = [1 for _ in scratchcards]

    for scratchcard in scratchcards:
        cardNumber, winningNumbers, yourNumbers = splitScratchcardTwo(scratchcard)
        winningNumbers = {int(num) for num in winningNumbers.split()}
        yourNumbers = {int(num) for num in yourNumbers.split()}
        matchingNumbersAmt = len(winningNumbers.intersection(yourNumbers))
        fillCardList(cardList, cardNumber, matchingNumbersAmt)

    return sum(cardList)

answerPartOne = partOne()
print(f"Answer part one: {answerPartOne}")
answerPartTwo = partTwo()
print(f"Answer part two: {answerPartTwo}")