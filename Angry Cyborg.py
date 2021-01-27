t = int(input())
for _ in range(t):
    n, q = map(int, input().split())

    start_count, end_count = [0]*(n + 1), [0]*(n + 1)
    start_sum, end_sum = [0]*(n + 1), [0]*(n + 1)

    for _ in range(q):
        l, r = map(int, input().split())
        start_count[l] += 1
        start_sum[l] += l

        end_count[r] += 1
        end_sum[r] += l

    count = 0
    x = 0
    for i in range(1, n + 1):
        count -= end_count[i - 1]
        x -= end_sum[i - 1]
        
        count += start_count[i]
        x += start_sum[i]

        print((i + 1)*count - x, end = ' ')
    print()
