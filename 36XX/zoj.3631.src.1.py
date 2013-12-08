# -*- coding: utf8 -*-

# 3487791 2013-12-08 23:58:19 Accepted 3631 Python 1130 4744 呆滞的慢板

"""
经典背包问题
经典背包变种，问题在于背包空间超大，因此要注意以下两点：
1. 背包需要用集合存放;
2. 由于空间太大，最坏情况可能有 2^30 个状态，因此需要进行折半;

折半的方法是，分别做两个 2^(n/2) 的背包，做完之后，枚举一个二分另一个。
"""

import sys

def binary_search(v, k):
    l = 0
    r = len(v)
    while l < r-1:
        m = l + r >> 1
        if v[m] <= k: l = m
        else: r = m
    return v[l]

lines = list(sys.stdin)

for i in range(0,len(lines),2):
    
    (n, m) = map(int, lines[i].split())
    vals = list(map(int, lines[i+1].split()))
    
    s = {0}
    for v in vals[0:n//2]:
        s |= {a+v for a in s if a+v <= m}
    k1 = sorted(s)

    s = {0}
    for v in vals[n//2:]:
        s |= {a+v for a in s if a+v <= m}

    ans = 0
    for x in s:
        if x <= m:
            ans = max(ans, x + binary_search(k1, m-x))

    print(ans)
