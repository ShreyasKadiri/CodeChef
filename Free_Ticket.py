def floyd_warshall(graph, N):
    dist = [[float('inf')] * (N + 1) for i in range(N + 1)]
    for u in graph:
        dist[u][u] = 0
        for v in graph[u]:
            dist[u][v] = graph[u][v]
    for k in range(1, N + 1):
        for i in range(1, N + 1):
            for j in range(1, N + 1):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist

def solve(C, F, cost):
    dist = floyd_warshall(cost, C)
    maximum = 0
    for i in range(1, C + 1):
        for j in range(1, C + 1):
            maximum = max(maximum, dist[i][j])
    return maximum

if __name__ == "__main__":
    C, F = list(map(int, input().strip().split()))
    cost = {i:{} for i in range(1, C + 1)}
    for flight in range(1, F + 1):
        x, y, p = list(map(int, input().strip().split()))
        cost[x][y] = p
        cost[y][x] = p
    print(solve(C, F, cost))
