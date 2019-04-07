T = int(input())
for i in range(1, T + 1):
    N = str(input())
    A = ''
    B = ''
    buildB = False
    for c in N: 
        if c == '4':
            A+= '3'
            B+= '1'
            buildB = True
        else:
            A+= c
            if buildB:
                B+= '0'
    print('Case #{i}: {A} {B}'.format(i=i, A=A, B=B))