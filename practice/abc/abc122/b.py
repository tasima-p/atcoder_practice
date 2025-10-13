# https://atcoder.jp/contests/abc122/tasks/abc122_b

ACGT = "ACGT"

if __name__ == "__main__":
  s = input()
  max_len = 0
  for i in range(len(s)):
    length = 0
    if s[i] in ACGT:
      for j in range(i, len(s)):
        if s[j] in ACGT:
          length += 1
        else:
          break
    max_len = max(max_len, length)
  print(max_len)
