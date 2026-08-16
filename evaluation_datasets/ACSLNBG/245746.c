#include <stdint.h>


int64_t func(int64_t x) {
    int64_t w = 0;
    int64_t temp_x = x;
    
    
    while (temp_x >= 3) {
        temp_x -= 3;
        w += 1;
    }
    
    //@ assert 0 <= w && w <= 33;
    //@ assert 0 <= temp_x && temp_x <= 2;
    //@ assert x == 3 * w + temp_x;
    
    //@ assert 0 <= w * w && w * w <= 1089;
    //@ assert 0 <= w * w * w && w * w * w <= 35937;
    
    int64_t ans = w * w * w;
    return ans;
}

int main() {
    return 0;
}
