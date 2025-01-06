n, m = map(int, input().split())
seq = []
used = set() 

def solve(depth):
    if depth == m:
        print(" ".join(map(str, seq))) 
        return
    
    for i in range(1, n + 1):
        if i not in used:
            used.add(i)
            seq.append(i)
            solve(depth + 1)
            seq.pop()
            used.remove(i)

solve(0)
