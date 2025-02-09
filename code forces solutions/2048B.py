import sys
 
sys.set_int_max_str_digits(6000)
 
def fact(x):
    if x == 0:
        return 1
    return x * fact(x - 1)
 
t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    n = min(n, 7)
    s = int(str(k) * fact(n))
    for i in range(1, 10, 2):
        if s % i == 0:
            print(i, end = ' ')
    print()