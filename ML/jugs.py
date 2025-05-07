def water_jug_algo():
    a, b = 0, 0         
    capacity_a = 4
    capacity_b = 3
    goal = 2

    steps = []

    while a != goal and b != goal:
        if b == 0:
            b = capacity_b  
        elif a + b <= capacity_a:
            a += b
            b = 0          
        else:
            b -= (capacity_a - a)
            a = capacity_a  
        if a == goal or b == goal:
            steps.append((a, b))
            break
        if a == capacity_a:
            a = 0         
        steps.append((a, b))

    print("Steps to reach 2L in a jug:")
    for s in steps:
        print(f"Jug4: {s[0]}L, Jug3: {s[1]}L")

water_jug_algo()
