#include <stdbool.h>

/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b <= 1000000000;
    requires 0 <= x <= 1000000000;
    requires (long long)a + (long long)b <= 9223372036854775807LL / 2;
    ensures \result == (a + b >= x && a <= x);
*/
bool is_possible_x_cats(long long a, long long b, long long x) {
    long long sum;
    bool result;
    
    sum = a + b;
    
    //@ assert sum == a + b;
    
    if (sum < x || a > x) {
        result = false;
    } else {
        //@ assert sum >= x && a <= x;
        result = true;
    }
    
    return result;
}
