#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == ((n % 10) == 9 || (n / 10) == 9);
*/
bool func(int n)
{
    int rem;
    int quotient;
    int temp_n;

    rem = n;
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant rem >= 0;
        loop invariant rem <= n;
        loop invariant rem == n || (rem % 10 == n % 10);
        loop assigns rem;
    */
    while (rem >= 10)
    {
        //@ assert rem >= 10;
        rem -= 10;
    }

    /*@
        loop invariant 10 <= n <= 99;
        loop invariant rem < 10;
        loop invariant rem == n % 10;
        loop assigns rem;
    */
    while (rem < 0)
    {
        //@ assert rem < 0;
        rem += 10;
    }

    quotient = 0;
    temp_n = n;
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= quotient <= n / 10;
        loop invariant temp_n >= 0;
        loop invariant temp_n == n - 10 * quotient;
        loop assigns quotient, temp_n;
    */
    while (temp_n >= 10)
    {
        //@ assert temp_n >= 10;
        quotient += 1;
        temp_n -= 10;
    }

    //@ assert ((rem) == (n) % 10);
    //@ assert ((quotient) == (n) / 10);
    return quotient == 9 || rem == 9;
}
