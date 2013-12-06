for t in range(int(raw_input())):

    A, B, C = map(int, raw_input().split())

    mn = 300*A*A + 100*(2*A+B)*B + 50*(2*(A+B)+C)*C
    mx = 50*C*C + 100*(2*C+B)*B + 300*(2*(C+B)+A)*A

    print mn, mx
