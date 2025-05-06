dist = [
    [0, 5, 9],
    [5, 0, 7],
    [9, 7, 0]
]
cities = [0, 1, 2]
start = 0
min_cost = float('inf')
best_path = []

for i in range(1, 3):
    for j in range(1, 3):
        if i != j:
            path = [start, i, j, start]
            cost = (
                dist[path[0]][path[1]] +
                dist[path[1]][path[2]] +
                dist[path[2]][path[3]]
            )
            if cost < min_cost:
                min_cost = cost
                best_path = path

print("Best Route:", best_path)
print("Minimum Cost:", min_cost)
