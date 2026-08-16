#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 10000;
    
    logic integer manual_division(integer n, integer divisor) = 
        n / divisor;
    
    lemma division_property:
        \forall integer n, divisor; 
        is_valid_range(n) && divisor == 1000 ==> 
        n == manual_division(n, divisor) * divisor + (n % divisor);
*/

/*@
    requires is_valid_range(n);
    ensures \result == 1000 * (n / 1000) || \result == 1000 * ((n / 1000) + 1);
    ensures \result >= n;
    ensures \result - n <= 1000;
*/
int func(int n)
{
    int quotient = 0;
    int remainder = n;
    int divisor = 1000;
    
    //@ assert is_valid_range(n);
    //@ assert remainder == n && quotient == 0;
    
    /*@
        loop invariant 0 <= quotient <= n / 1000;
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder >= 0;
        loop invariant is_valid_range(n);
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder == n - quotient * divisor;
    }
    
    //@ assert remainder < divisor;
    //@ assert remainder == n % divisor;
    
    if (remainder == 0)
    {
        //@ assert quotient * divisor == 1000 * (n / 1000);
        return quotient * divisor;
    }
    else
    {
        //@ assert (quotient + 1) * divisor == 1000 * ((n / 1000) + 1);
        return (quotient + 1) * divisor;
    }
}
