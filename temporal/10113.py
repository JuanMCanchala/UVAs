
from fractions import Fraction
from sys import stdin

G,name,code = list(),list(),dict()

def encode(s):
  global name,code,G
  if s not in code:
    code[s] = len(code)
    name.append(s)
    G.append(list())
  return code[s]

def solve(source, target):
  ans = None

  return ans

def main():
  line = stdin.readline()
  while len(line)!=0:
    tok = line.split()
    if tok[0][0]=='!':
      v0,c0,v1,c1 = int(tok[1]),encode(tok[2]),int(tok[4]),encode(tok[5])
      G[c0].append((c1, Fraction(v1, v0)))
      G[c1].append((c0, Fraction(v0, v1)))      
    else:
      c0,c1 = encode(tok[1]),encode(tok[3])
      ans = solve(c0, c1)
      # print(....)
    line = stdin.readline()
  # print(code)
  # print(name)
  # print(G)

main()