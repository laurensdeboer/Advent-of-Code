def getFileContents(filepath: str) -> list:
    with open(filepath) as file:
        return file.read().strip().split("\n\n")

def partOne():
    seeds, *maps = getFileContents("input.txt")
    seeds = list(map(int, seeds.split(": ")[1].split()))

    for singleMap in maps:
        ranges = []
        for mapLine in singleMap.splitlines()[1:]:
            dst, src, length = map(int, mapLine.split())
            ranges.append((dst, src, length))
        new = []
        for seed in seeds:
            for d, s, l in ranges:
                if s <= seed < s + l:
                    new.append(seed - s + d)
                    break
            else:
                new.append(seed)
        seeds = new
    return(min(seeds))

print(f"Answer part one: {partOne()}")
