#include <limits.h>

/*@ predicate is_valid_range(integer n) = 1 <= n <= 100; */

/*@ logic integer half_value(integer n) = n / 2; */
/*@ logic integer remainder_value(integer n) = n % 2; */

/*@ lemma half_remainder_sum: 
      \forall integer n; is_valid_range(n) ==> 
        half_value(n) + remainder_value(n) == n / 2 + n % 2; */

/*@ requires is_valid_range(n);
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
 */
int func(int n) {
    int half = 0;
    int temp_n = n;
    int is_negative = 0;
    
    //@ assert is_valid_range(n);
    
    if (n < 0) {
        is_negative = 1;
        temp_n = -temp_n;
    }
    
    /*@ loop invariant 0 <= temp_n <= 100;
        loop invariant half <= n / 2;
        loop invariant temp_n == n - 2 * half;
        loop invariant is_valid_range(n);
        loop assigns temp_n, half;
        loop variant temp_n;
     */
    while (temp_n >= 2) {
        temp_n -= 2;
        half += 1;
        //@ assert half <= n / 2;
    }
    
    int remainder = (temp_n == 1) ? 1 : 0;
    
    if (is_negative) {
        half = -half;
    }
    
    //@ assert half == n / 2;
    //@ assert remainder == n % 2;
    
    return half + remainder;
}
