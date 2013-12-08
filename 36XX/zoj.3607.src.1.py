# -*- coding: utf8 -*-

# 3487785 2013-12-08 23:29:44 Accepted 3607 Python 80 272 呆滞的慢板
# 贪心，注意关键点：
# 1. 第一次客人来的时间不是 0;
# 2. 只有在一个时间段 dt 大于此前所有的 dt 是，才更新最优值。
# 3. 无论是否采用当前时间段，每个 dt 都应该更新 mxt。

for t in range(int(raw_input())):
    n = int(raw_input())
    p = list(map(float, raw_input().split()))
    t = list(map(int, raw_input().split()))
    ans = (0, 0)
    mxt = t[0]
    acc = p[0]
    for i in range(1, n):
        dt = t[i] - t[i-1]
        if dt > mxt and acc/i > ans[1]:
            ans = (mxt, acc/i)
        mxt = max(mxt, dt)
        acc += p[i]
    if acc / n > ans[1]:
        ans = (mxt, acc/n)
    print '%.6f %.6f' % ans
