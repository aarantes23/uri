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
 
    Staged: 
    [
        (3, 2, [
                {'i': 1, 'h': 1, 'w': 2, 'l': 3}, 
                {'i': 2, 'h': 2, 'w': 1, 'l': 1}, 
                {'i': 3, 'h': 2, 'w': 2, 'l': 1}
            ]
        ), 
        (2, 1, [
                {'i': 32, 'h': 4, 'w': 5, 'l': 1}, 
                {'i': 25, 'h': 10, 'w': 1, 'l': 20}
                ]
        )
    ]  

    Curated:
    [
        (3, 2, [(1, 6), (2, 2), (3, 2)]), 
        (2, 1, [(25, 200), (32, 20)])
    ]

    Result:
    1 3
    25

"""

t = int(input())
p = [None] * t

for i in range(t):    
    nk = [int(x) for x in input().split()]

    p[i] = nk[0],nk[1],[]
    for j in range(nk[0]):        
        ihwl = [int(x) for x in input().split()]
        p[i][2].append({"i":ihwl[0], "h":ihwl[1], "w":ihwl[2], "l":ihwl[3]})

t = len(p)
for t in range(len(p)):
    r = [] 
    n = p[t][0]
    k = p[t][1]
    for n in range(len(p[t][2])):
        p[t][2][n] = p[t][2][n]["i"],(p[t][2][n]["h"] * p[t][2][n]["w"] * p[t][2][n]["l"])
    p[t][2].sort(key=lambda x: x[1],reverse=True)
    for i in range(k): 
        r.append(p[t][2][i][0])
    print(*r, sep = " ")
