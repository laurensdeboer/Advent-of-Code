from collections import deque

def getFileContents(filePath):
    with open(filePath) as file:
        return file.read().strip().splitlines()

def findS(grid):
    sR = sC = None
    for r, row in enumerate(grid):
        for c, ch in enumerate(row):
            if ch == 'S':
                sR = r
                sC = c
                break
        if sR is not None:
            break
    return sR, sC

def partOne():
    grid = getFileContents("input.txt")
    sR, sC = findS(grid)
    seen = {(sR, sC)}
    q = deque([(sR, sC)])

    while q:
        r, c = q.popleft()
        ch = grid[r][c]
        
        # Check upwards
        if (r > 0) and (ch in "S|JL") and (grid[r - 1][c] in "|7F") and ((r - 1, c) not in seen):
            seen.add((r - 1, c))
            q.append((r - 1, c))

        # Check downwards
        if (r < len(grid) - 1) and (ch in "S|7F") and (grid[r + 1][c] in "|LJ") and ((r + 1, c) not in seen):
            seen.add((r + 1, c))
            q.append((r + 1, c))

        # Check left
        if (c > 0) and (ch in "S-J7") and (grid[r][c - 1] in "-LF") and ((r, c - 1) not in seen):
            seen.add((r, c - 1))
            q.append((r, c - 1))

        # Check right
        if (c < len(grid[r]) - 1) and (ch in "S-LF") and (grid[r][c + 1] in "-J7") and ((r, c + 1) not in seen):
            seen.add((r, c + 1))
            q.append((r, c + 1))

    return int(len(seen) / 2)
    
print(f"Answer part one: {partOne()}")
