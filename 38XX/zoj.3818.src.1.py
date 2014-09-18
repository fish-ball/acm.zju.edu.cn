# 3776381	2014-09-18 17:40:28	Accepted	3818	Python	20	140

from sys import stdin

for case in range(int(stdin.readline()[:-1])):
    s = stdin.readline()[:-1]
    s = ''.join([c for c in s if c.isalnum()])
    found = False
    for a_len in range(1, len(s)):
        if found or a_len * 3 + 2 > len(s):
            break
        a = s[:a_len]
        for b_len in range(1, len(s)//2 + 1):
            if found or a_len * 3 + b_len * 2 > len(s):
                break
            b = s[a_len:a_len+b_len]
            if a == b:
                continue
            if s == a+b+a+b+a:
                found = True
            if len(s) > (a_len+b_len) * 3 and\
                    s.startswith(a+b+a+b) and s.endswith(a+b):
                c = s[(a_len+b_len)*2:-(a_len+b_len)]
                found = c not in (a, b)
    print('Yes' if found else 'No')
