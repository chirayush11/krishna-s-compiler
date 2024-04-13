# testing all operator and variable declaration


def main():
  print("Private2 testcase")
  a: int = 10
  b: str = "Hello"
  c: float = 1.3460
  print(c)
  d: int = 43
  var1: bool = True
  var2: bool = False
  grades: list[int] = [67, 100, 87, 56]
  print(grades[0])
  print(grades[3])

  # operators
  d = a + c
  d = a**2
  d = a - c
  d = a * c
  d = a // 2
  d = a / 2
  d = a % 2
  var1 = a < 2
  var2 = a > 2
  var1 = a >= 2
  var2 = a <= 2

  # logical operators
  if (var1 and var2):
    print("AND")
  elif var1 or var2:
    print("OR")
  elif not var1:
    print("NOT")


if __name__ == '__main__':
  main()
