T = int(input())
for i in range(1, T + 1):
    N = int(input())
    P = str(input())
    X = ''
    for c in P: 
        if c == 'S':
            X += 'E'
        else:
            X += 'S'
    print('Case #{i}: {X}'.format(i=i, X=X))

