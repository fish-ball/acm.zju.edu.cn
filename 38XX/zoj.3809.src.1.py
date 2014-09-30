# -*- coding: cp936 -*-
# 3783976	2014-09-30 17:53:26	Accepted	3809	Python	0	140	呆滞的慢板

from sys import stdin

T = int(stdin.readline())

for t in range(T):
    N = int(stdin.readline())
    H = list(map(int, stdin.readline().split()))
    print(sum([1 if H[i-1] < H[i] > H[i+1] else 0 for i in range(1, N-1)]))

