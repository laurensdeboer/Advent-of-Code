def getFileContents(filepath: str) -> list:
    with open(filepath) as file:
        return file.read().strip().split("\n\n")
    
def getSeeds(almanac) -> list:
    seeds = almanac[0].split(": ")[1]
    return seeds.split()

def partOne():
    almanac = getFileContents("temp.txt")
    seeds = getSeeds(almanac)
    mapping = {}

    for mapData in almanac[1:]:
        for mapLine in mapData.split("\n")[1:]:
            dst, src, len = map(int, mapLine.split())
            for i in range(len):
                dst2 = dst + i
                src2 = src + i
                mapping[src2] = dst2

print(f"Answer part one: {partOne()}")

# print(getSeeds())