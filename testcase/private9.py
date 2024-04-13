def display(a: float) -> None:
  print("The sum is: ")
  print(a)


def add(lst: list[int]):
  total: float = 0
  end: int = len(lst)
  i: int = -1
  for i in range(0, end):
    total = total + lst[i]
  display(total)


def main():
  lst: list[int] = [4, 5, 6, 7, 8]
  add(lst)


if __name__ == '__main__':
  main()
