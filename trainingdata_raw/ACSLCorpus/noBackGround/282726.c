#include <stdbool.h>

/*@ requires 1 <= a <= 10000;
    requires ((a) % 2 == 0);
    ensures \result == a + a / 2;
    assigns \nothing;
 */
int func(int a)
{
    // Variable declarations at scope top
    int quotient = 0;
    int remainder = a;
    int divisor = 2;
    
    //@ assert 1 <= a && a <= 10000;
    //@ assert ((a) % 2 == 0);
    
    /*@ loop invariant 1 <= a && a <= 10000;
        loop invariant ((a) % 2 == 0);
        loop invariant 0 <= quotient;
        loop invariant quotient <= a / 2;
        loop invariant remainder == a - quotient * 2;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
     */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == a - quotient * 2;
    }
    
    //@ assert remainder == a - quotient * 2;
    //@ assert remainder >= 0 && remainder < 2;
    //@ assert quotient == a / 2;
    
    //@ assert a + quotient <= 15000;
    return a + quotient;
}
