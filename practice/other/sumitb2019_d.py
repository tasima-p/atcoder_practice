# https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

import sys

def main():
  # 入力を受け取る
  N = int(sys.stdin.readline())
  S = sys.stdin.readline().strip()

  count = 0

  # 000から999までの暗証番号を試す
  for i in range(10):
    for j in range(10):
      for k in range(10):
        pin = str(i) + str(j) + str(k)

        # Sの中にpin[0] (1桁目) があるか探す
        pos1 = S.find(pin[0])
        if pos1 == -1:
          continue

        # pos1より後ろにpin[1] (2桁目) があるか探す
        pos2 = S.find(pin[1], pos1 + 1)
        if pos2 == -1:
          continue

        # pos2より後ろにpin[2] (3桁目) があるか探す
        pos3 = S.find(pin[2], pos2 + 1)
        
        # 3桁目まで見つかれば、この暗証番号は作成可能
        if pos3 != -1:
          count += 1
          
  print(count)

if __name__ == "__main__":
  main()