n = int(input())
k = int(input())

card = []
used = [False for _ in range(n)]
nums = []
rst = set()

for i in range(n):
    card.append(input())


def dfs(nums):
    if len(nums) == k:
        number = "".join(nums)
        rst.add(number)
        return 
    
    for i in range(n):
        if not used[i]:
            used[i] = True
            dfs(nums + [card[i]])
            used[i] = False
            
dfs(nums)

print(len(rst))
            