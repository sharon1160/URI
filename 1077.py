def main():
    n = int(input())

    while (n):
        infix = input()
        solve(infix)
        n = n - 1

def solve(infix):
    ops = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
    t = []
    for c in infix:
        if (c == '('):
            t.append(c)
        elif (c == ')'):
            ti = t.pop()
            while (t and ti != '('):
                print(ti, end='')
                ti = t.pop()
        elif (c in ops):
            if (not t):
                t.append(c)
            else:
                ti = t[len(t)-1]
                if (ti == '('):
                    t.append(c)
                elif (ops[c] > ops[ti]):
                    t.append(c)
                else:
                    while (t and ops[ti] >= ops[c]):
                        print(ti, end='')
                        t.pop()
                        if (t):
                            ti = t[len(t) - 1]
                            if (ti == '('):
                                break
                    t.append(c)
        else:
            print(c, end='')
    while (t):
        print(t.pop(), end='')
    print()


if __name__ == '__main__':
    main()
