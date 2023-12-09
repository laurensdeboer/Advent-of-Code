def getFileContents(filePath):
    with open(filePath) as file:
        return file.readlines()

def splitFileData(fileContents):
    instructions = fileContents[0].strip()
    nodesRaw = fileContents[2:]
    nodes = [nodeRaw for nodeRaw in nodesRaw]
    return instructions, nodes

def createNodeDict(nodes):
    nodeDict = {}
    for node in nodes:
        l,r = node.strip().split(" = ")
        nodeDict[l] = list(r[1:-1].split(', '))
    return nodeDict

def partOne():
    contents = getFileContents("input.txt")
    instructions, nodes = splitFileData(contents)
    nodeDict = createNodeDict(nodes)

    currentNode = "AAA"
    currentInstruction = 0
    count = 0

    while (currentNode != "ZZZ"):
        nodeIdx = 0 if instructions[currentInstruction] == 'L' else 1
        currentNode = nodeDict[currentNode][nodeIdx]
        currentInstruction = (currentInstruction + 1) % len(instructions)
        count += 1

    return count

print(f"Part one answer: {partOne()}")
