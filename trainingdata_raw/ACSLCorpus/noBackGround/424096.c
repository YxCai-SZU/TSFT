#include <stdbool.h>

/*@ requires 1 <= a <= 100 && 1 <= b <= 100;
    ensures \result == ((a + b) % 2 == 0);
    assigns \nothing;
 */
bool func(long a, long b)
{
    long sum = a + b;
    bool is_even = false;
    long abs_sum;
    
    if (sum < 0) {
        abs_sum = -sum;
    } else {
        abs_sum = sum;
    }
    
    /*@ loop invariant 0 <= abs_sum <= 200;
        loop invariant abs_sum <= a + b;
        loop invariant (((sum) % 2 == 0) == ((abs_sum) % 2 == 0));
        loop assigns abs_sum;
        loop variant abs_sum;
     */
    while (abs_sum >= 2) {
        //@ assert (((sum) % 2 == 0) == ((abs_sum) % 2 == 0));
        abs_sum -= 2;
    }
    
    if (abs_sum == 0) {
        is_even = true;
    }
    
    //@ assert (((sum) % 2 == 0) == ((abs_sum) % 2 == 0));
    //@ assert (sum % 2 == 0) == is_even;
    return is_even;
}
