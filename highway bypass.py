class PathNode:

    def __init__(self, row, col, st_x, st_y, p_count=0):
        self.x = row
        self.y = col
        self.pathCount = p_count

    def __str__(self):
        return str(self.x) + " | " + str(self.y) + " | " + str(self.pathCount)


class GraphUtil:
    def __init__(self, mat, R,C, d):
        self.mat = mat
        self.R = R
        self.C = C
        self.d = d
        self.tab = {}

    def isValidMove(self, r, c, blockVal):
        return r < self.R and c < self.C and self.mat[r][c] != blockVal

    def possbilePathUtil(self, r, c, blockVal, step,direction):

        if(not self.isValidMove(r, c, 0)):
            return 0
            
        if (r == self.R - 1 and c == self.C - 1):
            return 1

        if ((r,c,step,direction) in self.tab):
            return self.tab[(r,c,step,direction)]

        result = 0
        
        if direction == 1:
            if step < self.d:
                result = (result + self.possbilePathUtil(r, c + 1, blockVal, step + 1,1)) % 20011
            result = (result +  self.possbilePathUtil(r+1, c, blockVal, 1,2)) % 20011
        else:
            if step < self.d:
                result = (result + self.possbilePathUtil(r + 1, c, blockVal, step + 1, 2)) % 20011
            result = (result + self.possbilePathUtil(r, c + 1, blockVal, 1,1)) % 20011
        
        self.tab[(r,c,step,direction)] = result
        
        return result

    def possbilePath(self):
        if (not self.mat or len(self.mat) < 1):
            return 0

        return self.possbilePathUtil(0, 0, 0,0,2)


numbers = [int(n) for n in input().split()]

mat = [[int(n) for n in input().split()] for r in range(0, numbers[0])]

result = GraphUtil(mat, numbers[0], numbers[1], numbers[2])

print(result.possbilePath())
# print(result.count)# cook your dish here
