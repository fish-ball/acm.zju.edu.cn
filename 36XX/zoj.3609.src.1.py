# -*- coding: utf8 -*-

#1 http://en.wikipedia.org/wiki/Modular_inverse
#2 http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm

# 3487072 2013-12-06 16:01:19 Accepted 3609 Python 40 140 呆滞的慢板

"""
这道题是一道赤裸裸的模线性方程求解。
使用的算法可以参见 #2 参考的扩展欧几里得算法中，有一个专门的伪代码函数 inverse。
"""

def gcd(m, n): return gcd(n, m % n) if n else m 

# see the wiki pseudo-code.
def inverse(a, n):
    
    t = 0
    newt = 1
    r = n
    newr = a
    while newr != 0:
        quotient = r // newr
        (t, newt) = (newt, t - quotient * newt)
        (r, newr) = (newr, r - quotient * newr)
    if r > 1: return 0
    if t < 0: t += n
    return t

for t in range(int(raw_input())):
    (a, m) = map(int, raw_input().split())
    if m == 1: print(1)
    else: print(inverse(a, m) if gcd(a, m) == 1 else 'Not Exist')
