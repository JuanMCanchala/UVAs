def fib(n): return n if n<=1 else fib(n-2)+fib(n-1)
  # ans = None
  # if n<=1: ans = n
  # else: ans = fib(n-2)+fib(n-1)
  # return ans

def fib_memo(n, mem):
  ans = None
  if n in mem:
    ans = mem[n]
  else:
    ans = n if n<=1 else fib_memo(n-2, mem)+fib_memo(n-1, mem)
    mem[n] = ans
  return ans