"""
Athletics Track
https://onlinejudge.org/external/116/11646.pdf

Bisection

"""

from sys import stdin
import math

eps = 1e-8

# calcula el perímetro de la pista
def f(v, b, a):
  r = math.sqrt(((v * v) / 4) + ((b * b * v * v) / (4 * a * a)))
  theta = math.acos(v / (2 * r))
  arc = 2 * r * theta
  ans = 2 * v + 2 * arc
  return ans
  
def main():
  case = 1
  line = stdin.readline()
  while line != "":
    a, b = list(map(int, line.split(":")))
    low, hi = 0, 200

    while abs(hi - low) > eps:
    #while low <= hi and iter < 50:
      mid = (low + hi) / 2
      if f(mid, b, a) > 400: hi = mid
      else: low = mid
      #iter += 1

    print("Case %d: %.10f %.10f" % (case, mid, (b * mid) / a))
    case += 1
    line = stdin.readline()

main()