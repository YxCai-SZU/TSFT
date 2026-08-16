#include <limits.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 100;
    logic integer expected_result(integer x) = (x * 3 + 4) / 5;
*/

/*@
    requires valid_range(x);
    ensures \result == expected_result(x);
*/
int func(int x)
{
    int result;
    int quotient;
    int remainder;
    
    result = x * 3 + 4;
    quotient = 0;
    remainder = result;
    
    /*@
        loop invariant 0 <= x <= 100;
        loop invariant result == x * 3 + 4;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == result - quotient * 5;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 5)
    {
        //@ assert remainder >= 5;
        quotient += 1;
        remainder -= 5;
        //@ assert remainder == result - quotient * 5;
    }
    
    //@ assert quotient == expected_result(x);
    return quotient;
}

int main()
{
    return 0;
}
