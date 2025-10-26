#include <iostream>
#include <limits>

bool isOverflowMultiply(int mltp1, int mltp2)
{
  int MAX = std::numeric_limits<int>::max();
  int MIN = std::numeric_limits<int>::min();
  
  bool isOverflow = mltp1 > 0 && mltp2 > 0 && mltp1 > MAX / mltp2;
  isOverflow = isOverflow || (mltp1 < 0 && mltp2 < 0 && mltp1 < MAX / mltp2);
  isOverflow = isOverflow || (mltp1 > 0 && mltp2 < 0 && mltp2 < MIN / mltp1);
  isOverflow = isOverflow || (mltp1 < 0 && mltp2 > 0 && mltp1 < MIN / mltp2);

  return isOverflow;
}

int raisePower(int base, int power)
{
  int res = 1;
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
  int base = 0, power = 0;
  std::cin >> base >> power;
  
  int res = raisePower(base, power);
  if (base == 0 || res != 0) {
    std::cout << res << '\n';
  } else {
    std::cerr << "Overflow\n";
  }
  
}

