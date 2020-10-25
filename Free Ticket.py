# cook your dish here
_in = input().split(' ')
C = int(_in[0])
F = int(_in[1])

minDistance = [[float('inf') for _ in range(C)] for _ in range(C)]

for vertex in range(C):
    minDistance[vertex][vertex] = 0

for _ in range(F):
    _in = input().split(' ')
    x, y, p = int(_in[0]) - 1, int(_in[1]) - 1, int(_in[2])
    minDistance[x][y] = p
    minDistance[y][x] = p

for x in range(C):
    for y in range(C):
        for z in range(C):
            if minDistance[x][z] != float('inf') and minDistance[y][x] != float('inf'):
                if minDistance[y][z] > minDistance[y][x] + minDistance[x][z]:
                    minDistance[y][z] = minDistance[y][x] + minDistance[x][z]

maxCheapestCost = -float('inf')
for row in minDistance:
    if maxCheapestCost < max(row):
        maxCheapestCost = max(row)

print(maxCheapestCost)
