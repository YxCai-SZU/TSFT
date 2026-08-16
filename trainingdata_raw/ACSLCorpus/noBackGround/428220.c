#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000000000000 &&
        1 <= (a) <= (b) <= 1000000000000);
    ensures \result == (((b) / 2) >= n && n * 2 >= a);
*/
bool func(unsigned long long n, unsigned long long a, unsigned long long b)
{
    // Variable declarations at scope top
    unsigned long long quotient = 0;
    unsigned long long remainder = b;
    
    //@ assert remainder == b - 2 * quotient;
    
    /*@
        loop invariant 0 <= quotient <= ((b) / 2);
        loop invariant remainder == b - 2 * quotient;
        loop invariant (1 <= (n) <= 1000000000000 &&
        1 <= (a) <= (b) <= 1000000000000);
        loop assigns quotient, remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        quotient += 1;
        remainder -= 2;
        //@ assert remainder == b - 2 * quotient;
    }
    
    //@ assert quotient == ((b) / 2);
    //@ assert ((b) / 2) >= n ==> quotient >= n;
    
    return quotient >= n && n * 2 >= a;
}
