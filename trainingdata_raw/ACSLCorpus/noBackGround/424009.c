#include <stddef.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == (((n) / 100) * 100 + (((n) % 100) / 5) * 5);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result = 0;
    size_t remainder = n;
    size_t hundreds = 0;
    size_t fives = 0;

    //@ assert (1 <= (n) <= 10000);
    //@ assert remainder == n;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= hundreds <= n / 100;
        loop invariant remainder == n - hundreds * 100;
        loop invariant remainder >= 0;
        loop assigns hundreds, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder >= 100;
        hundreds += 1;
        remainder -= 100;
        //@ assert remainder == n - hundreds * 100;
    }

    //@ assert 0 <= remainder < 100;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= hundreds <= n / 100;
        loop invariant 0 <= fives <= (n - hundreds * 100) / 5;
        loop invariant remainder == n - hundreds * 100 - fives * 5;
        loop invariant remainder >= 0;
        loop assigns fives, remainder;
        loop variant remainder;
    */
    while (remainder >= 5)
    {
        //@ assert remainder >= 5;
        fives += 1;
        remainder -= 5;
        //@ assert remainder == n - hundreds * 100 - fives * 5;
    }

    //@ assert remainder == n - hundreds * 100 - fives * 5;
    //@ assert remainder < 5;
    
    result = hundreds * 100 + fives * 5;
    
    //@ assert result == (((n) / 100) * 100 + (((n) % 100) / 5) * 5);
    return result;
}
