#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((100 * (r) + 10 * (g) + (b)) % 4 == 0);
*/
bool func(long r, long g, long b) {
    long sum;
    bool is_divisible;
    long abs_sum;
    long remainder;
    
    sum = 100 * r + 10 * g + b;
    is_divisible = false;
    abs_sum = sum;
    
    if (sum < 0) {
        abs_sum = -sum;
    }
    
    remainder = abs_sum;
    /*@
        loop invariant 0 <= remainder <= abs_sum;
        loop invariant remainder % 4 == abs_sum % 4;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 4) {
        remainder -= 4;
    }
    
    if (remainder == 0) {
        is_divisible = true;
    }
    
    //@ assert is_divisible == (sum % 4 == 0);
    
    return is_divisible;
}
