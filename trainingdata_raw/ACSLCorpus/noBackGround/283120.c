#include <stdbool.h>
#include <limits.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires ((a) * (b)) <= LLONG_MAX;
    requires ((a) * (b)) >= LLONG_MIN;
    assigns \nothing;
    ensures \result == (((a) * (b)) % 2 != 0);
*/
bool func(long long a, long long b) {
    long long product = a * b;
    bool is_odd_result = false;
    long long abs_product;
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    /*@
        loop invariant 0 <= abs_product <= LLONG_MAX;
        loop invariant abs_product <= ((a) * (b));
        loop invariant (abs_product % 2 == 0) == (((a) * (b)) % 2 == 0);
        loop invariant (((a) * (b)) % 2 == 0) ==> !is_odd_result;
        loop assigns abs_product, is_odd_result;
    */
    while (abs_product > 0) {
        if (abs_product == 1) {
            is_odd_result = true;
            break;
        }
        
        //@ assert 0 <= abs_product - 2 <= ((a) * (b));
        
        abs_product -= 2;
    }
    
    //@ assert (((a) * (b)) % 2 != 0) == is_odd_result;
    return is_odd_result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
