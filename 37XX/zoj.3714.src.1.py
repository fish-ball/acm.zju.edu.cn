T = int(raw_input())

for t in range(T):
    (n, k) = map(int, raw_input().split())
    a = list(map(int, raw_input().split()))
    ans = sum(a[0:k])
    cur = ans
    for i in range(0, n):
        cur += a[k+i-n] - a[i]
        ans = max(ans, cur)
    print ans
