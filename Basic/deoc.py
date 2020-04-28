import time
import math
def calculate(f):
     def inner(*args,**kwargs):
          begin=time.time()
          r=f(*args,**kwargs)
          end=time.time()
          print("Total time taken -->",f.__name__,end-begin)
          return r
     return inner
@calculate
def f(n):
     return  math.factorial(n)

print(f(10))


