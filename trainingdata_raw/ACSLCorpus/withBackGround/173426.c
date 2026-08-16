#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 1000;
    
    logic integer manual_mod(integer n, integer divisor) = n % divisor;
    
    lemma mod_property:
        \forall integer n, divisor;
        is_valid_range(n) && divisor == 3 ==>
        manual_mod(n, divisor) == n % 3;
*/

/*@
    requires is_valid_range(n);
    ensures \result == (n % 3 == 0);
    assigns \nothing;
*/
bool func(int n)
{
    int quotient = 0;
    int remainder = n;
    int divisor = 3;
    
    //@ assert is_valid_range(n);
    //@ assert remainder == n;
    //@ assert divisor == 3;
    
    /*@
        loop invariant 1 <= n <= 1000;
        loop invariant 0 <= quotient <= n / divisor;
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == n - quotient * divisor;
    }
    
    //@ assert remainder == n - quotient * divisor;
    //@ assert remainder < divisor;
    //@ assert remainder == n % 3;
    
    return remainder == 0;
}
