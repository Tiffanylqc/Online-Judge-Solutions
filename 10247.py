import sys

facts = [0] * 4000
facts[0] = 1

for x in range (1, 4000):
    facts[x] = facts[x - 1] * x

def calcn(k, d):
    if d == 0:
        return 1
    else:
        return 1 + k * calcn(k, d - 1)

def solve(k, d, n):
    if d == 0:
        return 1
    subn = int((n - 1) / k)
    return pow(solve(k, d - 1, subn), k)* facts[n - 1] // pow(facts[subn], k)

for line in sys.stdin:
    k = int(line.split(' ')[0])
    d = int(line.split(' ')[1])
    n = calcn(k, d)
    print(solve(k, d, n))
