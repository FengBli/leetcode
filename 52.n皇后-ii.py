class Solution:
    def __init__(self):
        res = 0

    def pass_(self, bds, row, col, n):
        vsum = 0
        dsum = 0
        ddsum = 0

        for i in range(row, -1, -1):
            vsum += bds[i][col]
        
        j = row if row < col else col
        for i in range(0, j+1):
            dsum += bds[row-i][col-i]
        
        j = row if row < (n-col-1) else (n-col-1)
        for i in range(0, j+1):
            ddsum += bds[row-i][col+i]

        if vsum > 1 or dsum > 1 or ddsum > 1:
            return False
        return True

    def check(self, bds, row, n):
        for i in range(n):
            bds[row][i] = 1
            if self.pass_(bds, row, i, n):
                if row < n-1:
                    self.check(bds, row+1, n)
                else:
                    self.res += 1
            bds[row][i] = 0

    def totalNQueens(self, n: int) -> int:
        self.res = 0
        bds = [[0 for i in range(n)] for _ in range(n)]
        self.check(bds, 0, n)
        return self.res
        

if __name__ == "__main__":
    s = Solution()
    a = []
    for i in range(13):
        res = s.totalNQueens(i)
        # print(f'NQueens({i}) = {res}')
        a.append(res)
    print(a)