# -*- coding: utf8 -*-
# 3493626 2013-12-21 19:59:09 Accepted 3547 Python 770 712 呆滞的慢板

# generate primes
b = [True]*10000
p = []
for i in range(2, 10000):
    if b[i]:
        p.append(i)
        for j in range(i*i, 10000, i):
            b[i] = False

# return prime factors of n
def f(n):
    ans = []
    for x in p:
        if n % x == 0:
            ans.append(x)
            while n % x == 0: n //= x
        if n == 1: return ans
    if n > 1: ans.append(n)
    return ans

# summary of k^4
M = 1000000007
def s(k): return (k*(2*k+1)*(k+1)*(3*k*k+3*k-1))/30 #% M

# main
for t in range(int(raw_input())):

    n = int(raw_input())
    fact = f(n)

    ans = 0
    L = len(fact)
    for mask in range(1<<L):
        mult = sign = 1
        for i in range(L):
            if mask & (1<<i):
                mult *= fact[i]
                sign = -sign
        ans += sign*s(n//mult)*mult**4
        ans %= M

    print(ans)
    
    
