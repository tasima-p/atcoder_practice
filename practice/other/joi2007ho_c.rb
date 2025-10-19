# # https://www2.ioi-jp.org/joi/2006/2007-ho-prob_and_sol/2007-ho.pdf#page=5

# # input.txtからの入力を想定
# def parse_input
#   n = gets.to_i
#   # n個の座標を配列で受け取る
#   a = Array.new(n) { gets.split.map(&:to_i) }
#   [n, a]
# end

# def main
#   n, a = parse_input
#   max_volume = 0
#   existing = Array.new(5010) { Array.new(5010, false) }

#   a.each do |x, y|
#     existing[x][y] = true
#   end

#   a.each_cons(2) do |(x1, y1), (x2, y2)|
#     dx = (x2 - x1).abs
#     dy = (y2 - y1).abs

#     x3, y3, x4, y4 = nil, nil, nil, nil

#     x3 = x1 - dy
#     y3 = y1 + dx
#     x4 = x2 - dy
#     y4 = y2 + dx
#     if existing[x3][y3] && existing[x4][y4]
#       area = dx * dx + dy * dy
#       max_volume = [max_volume, area].max
#     end

#     x3 = x1 + dy
#     y3 = y1 - dx
#     x4 = x2 + dy
#     y4 = y2 - dx
#     if existing[x3][y3] && existing[x4][y4]
#       area = dx * dx + dy * dy
#       max_volume = [max_volume, area].max
#     end

#   end
#   puts max_volume
# end

# if __FILE__ == $0
#   main
# end

# input.txtからの入力を想定
# Setライブラリを読み込む
require 'set'

def parse_input
  n = gets.to_i
  # n個の座標を配列で受け取る
  a = Array.new(n) { gets.split.map(&:to_i) }
  [n, a]
end

def main
  n, a = parse_input
  max_area = 0 # 変数名を max_volume から max_area に変更 (わかりやすさのため)
  
  # 1. メモリ対策: 2D配列の代わりに Set を使う
  existing = Set.new
  a.each do |x, y|
    existing.add([x, y])
  end

  # 3-1. 論理エラー修正: .each_cons(2) -> .combination(2)
  # 全てのペアを試す
  a.combination(2) do |(x1, y1), (x2, y2)|
    
    # 3-2. 論理エラー修正: .abs を削除
    dx = x2 - x1
    dy = y2 - y1

    # 1点目 (p3, p4) を探す
    # (x1, y1) から (-dy, dx) のベクトル
    x3 = x1 - dy
    y3 = y1 + dx
    # (x2, y2) から (-dy, dx) のベクトル
    x4 = x2 - dy
    y4 = y2 + dx
    
    # 2. 実行時エラー対策: .include? を使う (範囲外アクセスも自動でfalseになる)
    if existing.include?([x3, y3]) && existing.include?([x4, y4])
      area = dx * dx + dy * dy
      max_area = [max_area, area].max
    end

    # 2点目 (p3', p4') を探す
    # (x1, y1) から (dy, -dx) のベクトル
    x3 = x1 + dy
    y3 = y1 - dx
    # (x2, y2) から (dy, -dx) のベクトル
    x4 = x2 + dy
    y4 = y2 - dx
    
    if existing.include?([x3, y3]) && existing.include?([x4, y4])
      area = dx * dx + dy * dy
      max_area = [max_area, area].max
    end
  end
  
  puts max_area
end

if __FILE__ == $0
  main
end