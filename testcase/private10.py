# Recursive binary search


# Returns index of x in arr if present, else -1
def binary_search(arr: list[int], low: int, high: int, x: int) -> None:
  # Check base case
  if high >= low:
    mid = (high + low) // 2

    # If element is present at the middle itself
    if arr[mid] == x:
      return mid

    # If element is smaller than mid, then it can only
    # be present in left subarray
    elif arr[mid] > x:
      return binary_search(arr, low, mid - 1, x)

    # Else the element can only be present in right subarray
    else:
      return binary_search(arr, mid + 1, high, x)

  else:
    # Element is not present in the array
    return -1


def main():
  arr: list[int] = [2, 3, 4, 10, 40]
  max_len: int = len(arr)
  x: int = 10

  result: int = -1
  result = binary_search(arr, 0, max_len - 1, x)

  if result != -1:
    print("Element is present at index")
    print(result)
  else:
    print("Element is not present in array")


if __name__ == '__main__':
  main()
