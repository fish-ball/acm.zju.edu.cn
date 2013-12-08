# -*- coding: utf8 -*-
# 3487724 2013-12-08 22:12:35 Accepted 3603 Python 300 272 呆滞的慢板

# 求一组字符集合的串联交集。
# 利用神 python 切这种题真是爽，有效代码 6 行！
import collections

for t in range(int(raw_input())):
    ans = False
    for n in range(int(raw_input())):
        s = collections.Counter(raw_input())
        ans = ans & s if ans else s
    print ''.join([k*ans[k] for k in sorted(ans)])
