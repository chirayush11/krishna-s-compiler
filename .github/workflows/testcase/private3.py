def find_primes(nums: list[int]) -> int:
  num: int = 0
  len_: int = len(nums)
  count: int = 0

  for i in range(len_):
    num = nums[i]
    j: int = 2
    is_prime: bool = True
    end: int = (num // 2) + 1
    for j in range(2, end):
      if (num % j) == 0:
        is_prime = False
        break
    if is_prime:
      count += 1

  return count


def main():
  nums: list[int] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  primes = find_primes(nums)
  print(primes)


if __name__ == "__main__":
  main()
