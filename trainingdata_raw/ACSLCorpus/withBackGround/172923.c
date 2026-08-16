#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    predicate is_valid_num(integer num, integer n) = 1 <= num && num <= n;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n) {
    int num;
    int result;
    
    num = 1;
    result = 0;
    
    /*@
        loop invariant is_valid_n(n);
        loop invariant is_valid_num(num, n);
        loop assigns num, result;
        loop variant n - num;
    */
    while (num < n) {
        //@ assert 1 <= num && num <= n;
        
        if (((num + 1) % 3 == 0) || ((num + 2) % 3 == 0)) {
            result = 1;
            return result;
        }
        
        num = num + 1;
    }
    
    result = 0;
    return result;
}
