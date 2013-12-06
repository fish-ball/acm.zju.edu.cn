for T in range(int(raw_input())):

    n, m = map(int, raw_input().split())

    s = set()

    for x, y in zip(map(int, raw_input().split())
                    , map(int, raw_input().split())):
        s.add((min(x,y), max(x, y)))

    print '%.3f' % (float(len(s)) / n)
