#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 != 0;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> is_even(n);
    ensures \result == 0 ==> is_odd(n);
*/
int func(int n)
{
    int result;
    int i;
    
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        //@ assert is_even(n);
        result = 1;
        //@ assert result == 1 && is_even(n);
        return result;
    } else {
        //@ assert is_odd(n);
        i = 0;
        
        /*@
            loop invariant 0 <= i <= 10;
            loop invariant is_odd(n);
            loop assigns i;
            loop variant 10 - i;
        */
        while (i < 10) {
            //@ assert 0 <= i < 10 && is_odd(n);
            
            if (i >= 10) {
                // This will never be true, but is here for illustration
                result = 1;
                //@ assert result == 1;
                return result;
            }
            
            i = i + 1;
            //@ assert 1 <= i <= 10 && is_odd(n);
        }
        
        result = 0;
        //@ assert result == 0 && is_odd(n);
        return result;
    }
}
