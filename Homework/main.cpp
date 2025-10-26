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
            throw std::logic_error("Overflow");
        }
    
        
    }
    
    
}


int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    
    
    
    
}
