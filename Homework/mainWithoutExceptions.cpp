#include <iostream>
#include <limits>

bool isOverflowMultiply(int a, int b) {
    int MAX = std::numeric_limits<int>::max();
    int MIN = std::numeric_limits<int>::min();
    if (a > 0 && b > 0 && a > MAX/b) return true;
    else if (a < 0 && b < 0 && a < MAX/b) return true;
    else if (a > 0 && b < 0 && b < MIN/a) return true;
    else if (a < 0 && b > 0 && a < MIN/b) return true;
    return false;
}

int raisePower(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (isOverflowMultiply(res, a)){
            return 0;
        }
        res *= a;
        b--;
    }
    return res;
}


int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    
    int power = raisePower(a, b);
    if (power != 0){
        std::cout << power << '\n';
    } else {
        std::cerr << "Overflow\n";
    }
    
}

