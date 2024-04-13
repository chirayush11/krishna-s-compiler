def fibonacci(n: int) -> int:
  if n <= 0:
    return 0
  elif n == 1:
    return 1
  else:
    return fibonacci(n - 1) + fibonacci(n - 2)


def main():
  n: int = 10  # Example: To find the 10th Fibonacci number
  result: int = fibonacci(n)
  print("Fibonacci number is:")
  print(result)


if __name__ == "__main__":
  main()
