#include <stdbool.h>
#include <limits.h>


bool func(long long a, long long b) {
    long long product;
    bool is_odd;
    long long abs_product;

    product = a * b;
    is_odd = false;
    abs_product = product < 0 ? -product : product;

    
    while (abs_product > 0) {
        if (abs_product == 1) {
            is_odd = true;
            break;
        }
        
        //@ assert abs_product >= 2;
        abs_product -= 2;
    }

    return is_odd;
}


int main() {
    return 0;
}
