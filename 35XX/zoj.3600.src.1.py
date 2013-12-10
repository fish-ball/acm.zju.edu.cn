# -*- coding: utf8 -*-

"""
3488427 2013-12-10 23:15:59 Accepted 3600 Python 80 72 呆滞的慢板

水题，模拟，注意一下容易 WA：
1. 时间费用是连续的，不是阶跃的；
2. 注意 3-10 公里之间的费用；
"""

def old_price(d, t):
    return int(10 + min(max(0,d-3), 7)*2 + max(0,d-10)*3 + t*0.4 + 1 + 0.5)

def new_price(d, t):
    return int(11 + min(max(0,d-3), 7)*2.5 + max(0,d-10)*3.75 + t*0.625 + 0.5)

for t in range(int(raw_input())):
    (d, t) = map(int, raw_input().split())
    print new_price(d,t) - old_price(d,t)
