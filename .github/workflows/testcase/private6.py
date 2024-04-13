# Recursion
def factorial(n: int) -> int:
  if n <= 0:
    return 1
  else:
    return n * factorial(n - 1)


# Functions
def area(length: int, width: int) -> int:
  if width > 0:
    return 3.14 * length * length
  else:
    return length * width


# Classes and objects
class Vehicle:

  def __init__(self, make: str, model_: str):
    self.make: str = make
    self.model: str = model_

  def start(self) -> None:
    print(self.make)
    print(self.model)


class Car(Vehicle):

  def __init__(self, make: str, model_: str, year: int):
    self.make = make
    self.model = model_
    self.year: int = year

  def start(self) -> None:
    print(self.year)
    print(self.make)
    print(self.model)


def main():
  # Primitive data types
  x: int = 42
  y: float = 3.14
  s: str = "hello"
  b: bool = True

  # 1D list
  lst: list[int] = [1, 2, 3, 4, 5]

  # Arithmetic operators
  a: float = x + y
  b: int = x - y
  c: float = x * y
  d: float = x / y
  e: int = x // y
  f: float = x % y

  # Relational operators
  print(x == y)
  print(x != y)
  print(x > y)
  print(x < y)
  print(x >= y)
  print(x <= y)

  # Logical operators
  print(True and False)
  print(True or False)
  print(not True)

  # Bitwise operators
  p: int = 10
  q: int = 11
  print(p & q)
  print(p | q)
  print(p ^ q)
  print(~p)

  # Assignment operators
  x = 5
  x += 3
  x -= 2
  x *= 4
  x /= 3
  x //= 2
  x %= 3
  x **= 2
  y = 2
  y &= 7
  y |= 8
  y ^= 18
  y <<= 2
  y >>= 2

  # Control flow
  if x > 10:
    print("x is greater than 10")
  elif (x < 5):
    print("x is less than 5")
  else:
    print("x is between 5 and 10")

  # Loops
  for i in range(1, 5):
    print(i)

  i = 0
  while i < 5:
    print(i)
    i += 1
    if i == 3:
      break

  fact: int = factorial(5)
  print(fact)

  ar: int = area(5, 3)
  print(ar)

  car = Car("Toyota", "Camry", 2020)
  car.start()


if __name__ == '__main__':
  main()
