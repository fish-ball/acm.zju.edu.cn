# -*- coding: utf8 -*-
#3492415 2013-12-19 23:48:26 Accepted 3519 Python 220 140 呆滞的慢板

import sys

n = 0

for line in sys.stdin:
    
    if n == 0:
        
        n, ip = map(int, line.split())
        
    else:
        
        r = 0

        for x in sorted(map(int, line.split())):
            if x <= ip: r += 1
            else: ip += 2

        print(ip+r)

        n = 0
        



    
