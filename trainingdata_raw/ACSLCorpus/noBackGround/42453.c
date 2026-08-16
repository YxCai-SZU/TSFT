#include <stdbool.h>

/*@
    requires 10 <= a <= 99;
    ensures \result == (a % 10 == 9 || a >= 90);
*/
bool func(unsigned long long a)
{
    unsigned long long remainder;
    remainder = a;

    /*@
        loop invariant (10 <= (a) <= 99 &&
        (remainder) <= (a) &&
        (remainder) >= 0 &&
        ((remainder) == (a) || (remainder) == (a) - 10 || (remainder) == (a) - 20 || 
         (remainder) == (a) - 30 || (remainder) == (a) - 40 || (remainder) == (a) - 50 ||
         (remainder) == (a) - 60 || (remainder) == (a) - 70 || (remainder) == (a) - 80 || 
         (remainder) == (a) - 90));
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 10)
    {
        //@ assert (10 <= (a) <= 99 &&         (remainder) <= (a) &&         (remainder) >= 0 &&         ((remainder) == (a) || (remainder) == (a) - 10 || (remainder) == (a) - 20 ||           (remainder) == (a) - 30 || (remainder) == (a) - 40 || (remainder) == (a) - 50 ||          (remainder) == (a) - 60 || (remainder) == (a) - 70 || (remainder) == (a) - 80 ||           (remainder) == (a) - 90));
        remainder -= 10;
    }

    /*@
        loop invariant (10 <= (a) <= 99 &&
        (remainder) < 10 &&
        (remainder) >= -10 &&
        ((remainder) == (a) - 10 * ((a) / 10) || (remainder) == (a) - 10 * ((a) / 10) + 10));
        loop assigns remainder;
        loop variant 10 + remainder;
    */
    while (remainder < 0)
    {
        //@ assert (10 <= (a) <= 99 &&         (remainder) < 10 &&         (remainder) >= -10 &&         ((remainder) == (a) - 10 * ((a) / 10) || (remainder) == (a) - 10 * ((a) / 10) + 10));
        remainder += 10;
    }

    //@ assert remainder == a % 10;
    return (remainder == 9) || (a >= 90);
}
