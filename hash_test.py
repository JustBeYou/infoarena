modulo = (2 << 17) - 1
def h1(x, y):
    return (x + y) % modulo
def h2(x, y):
    return (x * y) % modulo
def h3(x, y):
    return ((x + y) * (x + y + 1) / 2 + y) % modulo
def h4(x, y):
    return ((x << 4) + (y >> 4)) % modulo
def h5(x, y):
    return ((x << 4) ^ (y >> 4)) % modulo
def h6(x, y):
    return ((x << 4) * 13 + 97 * (y >> 4)) % modulo
def h7(x, y):
    return (((x << 4) * 13) ^ (97 * (y >> 4))) % modulo

functions = [
    h1,h2,h3,h4,h5,h6,h7
]

def evaluate(h, maxx, maxy):
    statistics = {}
    for x in range(maxx):
        for y in range(maxy):
            r = h(x, y)
            try:
                statistics[r] += 1
            except:
                statistics[r] = 1

    return statistics

from time import time
for i, h in enumerate(functions):
    start = time()
    r = evaluate(h, 5000, 50000)
    end = time()
    mean = 0
    for k in r.keys():
        mean += r[k]
    mean = float(mean) / len(r.keys())
    print ("h{} : {} took {}s".format(i+1, mean, end - start))
