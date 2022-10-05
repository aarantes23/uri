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
        (2, 1, [(25, 20), (32, 20)])
    ]

    Result:
    1 3
    25

"""

def merge_sort(unsorted_list):
   if len(unsorted_list) <= 1:
      return unsorted_list

   middle = len(unsorted_list) // 2
   left_list = unsorted_list[:middle]
   right_list = unsorted_list[middle:]

   left_list = merge_sort(left_list)
   right_list = merge_sort(right_list)
   return list(merge(left_list, right_list))


def merge(left_half,right_half):
   res = []
   while len(left_half) != 0 and len(right_half) != 0:      
        if left_half[0][1] > right_half[0][1]:
            res.append(left_half[0])
            left_half.remove(left_half[0])
        elif left_half[0][1] == right_half[0][1]:
            if left_half[0][0] < right_half[0][0]:
                res.append(left_half[0])
                left_half.remove(left_half[0])
            else:
                res.append(right_half[0])
                right_half.remove(right_half[0])
        else:
            res.append(right_half[0])
            right_half.remove(right_half[0])
   if len(left_half) == 0:
      res = res + right_half
   else:
      res = res + left_half
   return res

t = int(input())
p = [None] * t
s = []

if t<=20:    
    for i in range(t):
        n, k = map(int, input().split())

        if n>=1 and n<=100000:
            if k>=1 and k<=n:
                p[i] = n,k,[]
                for j in range(n):
                    id,h,w,l = map(int, input().split())
                    p[i][2].append((id,(h * w * l)))

    for i in range(t):
        r = []
        
        s.append(merge_sort(p[i][2]))
        
        if p[i][1] == 1:
            del s[i][-(p[i][1]):]
        else: 
            del s[i][-((p[i][1])-1):]            
        
        for j in range(len(s[i])):
            r.append(s[i][j][0])
        print(*r, sep = " ")
