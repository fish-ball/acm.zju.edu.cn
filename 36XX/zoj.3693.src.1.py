# -*- coding: utf8 -*-
# 3488130 2013-12-09 23:30:57 Accepted 3693 Python 0 140 呆滞的慢板

import sys

for line in sys.stdin:
    n, w, k = map(float, line.split())
    print '%.2f' % ((n+2-(n+2)//k)*w*0.5+1e-6)
