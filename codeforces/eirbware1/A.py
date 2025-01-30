def find_ops(n, a):
    # finds min num of operations
    m = min(a)
    maxi = max(a)
    return maxi - m

if __name__ == "__main__":
    t = int(input())
    a_s = []
    for i in range(t):
        n = int(input())
        a = list(map(int, input().split(" ")))
        assert len(a) == n
        a_s.append(a)
        
    for a in a_s:
        print(find_ops(n, a))