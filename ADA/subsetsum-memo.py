def subsetsum(A, n, x):
  ans = None
  if n==0: ans = x==0
  else:
    ans = subsetsum(A, n-1, x)
    if A[n-1]<=x: ans = ans or subsetsum(A, n-1, x-A[n-1])
  return ans

def subsetsum_memo(A, n, x, mem):
  ans,key = None,(n, x)
  if key in mem:
    ans = mem[key]
    # print('usando {0}'.format(key))
  else:
    if n==0: ans = x==0
    else:
      ans = subsetsum_memo(A, n-1, x, mem)
      if A[n-1]<=x: ans = ans or subsetsum_memo(A, n-1, x-A[n-1], mem)
    mem[key] = ans
    # print('calculando {0}'.format(key))
  return ans