def fizz_buzz_sum(target):
  n3, n5 = 3, 5
  sum = 0
  s = set()
  while n3 < target and n3 not in s:
    s.add(n3)
    n3 += 3
  while n5 < target and n5 not in s:
    s.add(n5)
    n5 += 5
  print(s)
  print("\n")
  print(n5)
  for x in s:
    sum+=x
  return sum

print(fizz_buzz_sum(100))

