# -*- coding: cp936 -*-
# 3783987	2014-09-30 18:20:00	Accepted	3776	Python	10	140	呆滞的慢板

from sys import stdin

for T in range(int(stdin.readline())):

    stdin.readline()

    a = sum(map(int, stdin.readline().split()))
    b = sum(map(int, stdin.readline().split()))

    print('Draw' if a == b else 'Calem' if a > b else 'Serena')
