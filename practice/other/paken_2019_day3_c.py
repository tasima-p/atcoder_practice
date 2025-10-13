# https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c

if __name__ == "__main__":
  n, m = map(int, input().split())
  A = [list(map(int, input().split())) for _ in range(n)]

  max_sum_two_row = 0
  for i in range(m):
    for j in range(i+1,m):
      sum_two_row = sum(max(A[k][i], A[k][j]) for k in range(n))
      if sum_two_row > max_sum_two_row:
        max_sum_two_row = sum_two_row
  print(max_sum_two_row)
