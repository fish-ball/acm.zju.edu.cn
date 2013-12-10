# -*- coding: utf8 -*-

"""
3488440 2013-12-10 23:39:57 Accepted 3542 Python 50 140 呆滞的慢板
简单模拟题，用 python 也是淋漓尽致，
"""

import sys

for line in sys.stdin:
    line = line[:-1]
    for l in range(0, len(line), 16):
        buf = '%04x: ' % l
        s = line[l:l+16]
        for i in range(0, 16, 2):
            buf += '%02x' % ord(s[i]) if s[i:i+1] else '  '
            buf += '%02x ' % ord(s[i+1]) if s[i+1:i+2] else '   '
        print(buf + ''.join(c.lower() if c.isupper() else c.upper() for c in s))
