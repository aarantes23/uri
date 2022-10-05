# -*- coding: utf-8 -*-

## Desenvolvido por Arthur Arantes Faria
## arthurarantes23@hotmail.com

# https://www.beecrowd.com.br/judge/pt/problems/view/2720

""" 
    Input Example
    Raw input:
    2
    3 2
    1 1 2 3
    2 2 1 1
    3 2 2 1
    2 1
    32 4 5 1
    25 10 1 2

    Curated:
    [
        (3, 2, [(1, 6), (3, 4), (2, 2)]), 
        (2, 1, [(25, 200), (32, 20)])
    ]

    Result:
    1 3
    25

"""

t = int(input())
p = [None] * t

if t<=20:
    for i in range(t):
        nk = [int(x) for x in input().split()]

        if nk[0]>=1 and nk[0]<=100000:
            if nk[1]>=1 and nk[1]<=nk[0]:
                p[i] = nk[0],nk[1],[]
                for j in range(nk[0]):
                    ihwl = [int(x) for x in input().split()]
                    p[i][2].append([ihwl[0],(ihwl[1] * ihwl[2] * ihwl[3])])
                
                p[i][2].sort(key=lambda x: x[0],reverse=False)
                p[i][2].sort(key=lambda x: x[1],reverse=True)
                
                if p[i][1] == 1:
                    del p[i][2][-(nk[1]):]
                else: 
                    del p[i][2][-(nk[1]-1):]

    for i in range(t):
        r = []
        for j in range(p[i][1]):
            r.append(p[i][2][j][0])
        print(*r, sep = " ")
