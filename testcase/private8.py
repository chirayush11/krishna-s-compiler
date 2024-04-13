def main():
  name1: str = "Dragon book"
  name2: str = "Arc book"
  name3: str = "Tiger book"

  if name1 < name2:
    print("Name1 is smaller than Name2")
  else:
    print("Name1 is greater than Name2")

  if name1 < name2 and name2 < name3:
    print("Name1 is smaller than Name2 and Name3")


if __name__ == '__main__':
  main()
