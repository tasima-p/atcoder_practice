# https://atcoder.jp/contests/abc095/tasks/arc096_a

if __name__ == "__main__":
  a, b, c, x, y = map(int, input().split())
  if a + b > 2 * c:
    cost = 2 * c * min(x, y)
    if x > y:
      cost += min(a, 2 * c) * (x - y)
    else:
      cost += min(b, 2 * c) * (y - x)
  else:
    cost = a * x + b * y
  print(cost)
