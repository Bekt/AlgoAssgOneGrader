import random

def op():
    op.counter += 1
    f = open(str(op.counter) + '.in', 'w')
    return f

def wr(li):
    f = op()
    f.write(str(len(li)) + '\n')
    for item in li:
        f.write(str(item) + ' ')
    f.write('\n')
    f.close()

op.counter = 0

cases = []
cases.append([1, 2, 4, 5, 1, 9, 4, 3])
cases.append([1, 8, 2, 7, 3, 6, 4, 5])
cases.append([1804289383, 846930886, 1681692777, 1714636915, 1957747793, 424238335, 719885386, 1649760492, 596516649, 1189641421, 1025202362, 1350490027, 783368690, 1102520059, 2044897763, 1967513926])
cases.append([8, 2, 3, 4, 5, 6, 7, 1])
cases.append([-42])
cases.append([42])
cases.append([42, -42])
cases.append([-42, 42])
cases.append([100, 10, 1])
cases.append([1, 10, 100])
cases.append([i for i in xrange(-1000, 1000, 20)])
cases.append([i for i in xrange(0, 100)])
cases.append([i for i in xrange(1000, -1000, -20)])
cases.append([i for i in xrange(100, 0, -1)])
cases.append([0] * 99)
cases.append([10] * 100)
cases.append([-10] * 100)
cases.append([i for i in xrange(1000, 1050)] + [i for i in xrange(1050, 1000, -1)])
cases.append([10 for i in xrange(50)] + [-10 for i in xrange(50)])
cases.append([-10 for i in xrange(50)] + [10 for i in xrange(50)])

si = 100
while len(cases) < 100:
    cases.append([random.randint(-2147483647, 2147483646) for i in xrange(si)])
    si -= 1

for case in cases:
    wr(case)

