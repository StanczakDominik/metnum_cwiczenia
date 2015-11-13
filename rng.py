import matplotlib.pyplot as plt

x = 0

def rng(n):
    global x
    a = 1103515245
    c = 12345
    m = 2**31
    for i in range(n):
        x = (a*x+c) % m
        yield x

N=100000

y = [x for x in rng(N)]
x = range(N)

plt.hist(y, bins=1000, color=None, alpha=1, edgecolor=None)
plt.show()

for i, random_variable in enumerate(y):
    print(i, random_variable)
