#include <iostream>
#include <limits>

bool isOverflowMultiply(size_t mltp1, size_t mltp2)
{
  size_t MAX = std::numeric_limits<size_t>::max();
  bool isOverflow = mltp1 && mltp2 && mltp1 > MAX / mltp2;
  return isOverflow;
}

size_t raisePower(size_t base, size_t power)
{
  size_t res = 1;
  while (power > 0) {
    if (isOverflowMultiply(res, base)) {
      return 0;
    }
    res *= base;
    power--;
  }
  return res;
}


int main()
{
  size_t base = 0, power = 0;
  std::cin >> base >> power;
  
  size_t res = raisePower(base, power);
  if (base == 0 || res != 0) {
    std::cout << res << '\n';
  } else {
    std::cerr << "Overflow\n";
  }
  
}

