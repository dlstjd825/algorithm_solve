n, m = map(int, input().split())
seq = []
used = [False for _ in range(0, n)]

def solve(seq):
    if (len(seq) == m):
        for num in seq:
            print(num, end=" ")
        print()
        return
    
    for i in range(0, n):
        if not used[i]:
            used[i] = True
            solve(seq + [i+1])
            used[i] = False
    
solve(seq)
