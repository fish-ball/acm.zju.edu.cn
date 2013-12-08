# -*- coding: utf8 -*-
import sys

# 3487680 2013-12-08 20:56:03 Accepted 3665 Python 960 140 呆滞的慢板

# 寻找前 n 项和为 s 或 s-1 的等比数列的公比，失败返回 0。
def find_q(s, n):
    # r 的初值是效率的瓶颈！
    l, r = 1, int(s**(1.0/n)) + 1
    while l < r - 1:
        q = l + r >> 1
        if q*(q**n-1) in (s*(q-1), (s-1)*(q-1)):
            return q
        elif q*(q**n-1) > s*(q-1):
            r = q
        else: l = q
    return 0

for line in sys.stdin:
    n = int(line)
    a = (1, n - 1)
    for r in range(2, 41):
        q = find_q(n, r)
        if q and r * q < a[0] * a[1]:
            a = (r, q)
    print a[0], a[1]
