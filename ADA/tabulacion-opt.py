def ks(B, W, C):
  N = len(B)
  tab = [ 0 for _ in range(C+1) ]
  n,c = 1,C
  while n!=N+1:
    if c==-1: n,c = n+1,C
    else:
      if c>=W[n-1]: tab[c] = max(tab[c], B[n-1]+tab[c-W[n-1]])
      c -= 1
  return tab[C]