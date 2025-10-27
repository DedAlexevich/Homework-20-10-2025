#include <iostream>
#include <limits>

bool isOverflowMultiply(size_t mltp1, size_t mltp2)
{
  size_t MAX = std::numeric_limits<size_t>::max();
  return mltp1 != 0 && mltp2 != 0 && mltp1 > MAX / mltp2;
}

size_t raisePower(size_t base, size_t power)
{
  size_t res = 1;
  while (power > 0) {
    if (isOverflowMultiply(res, base)) {
      throw std::logic_error("Overflow");
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

  try {
    size_t res = raisePower(base, power);
    std::cout << res << '\n';
  } catch (const std::logic_error &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
