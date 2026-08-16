#include <stdbool.h>

/*@
    predicate is_even_inv(integer num, integer number) =
        num >= 0 &&
        num <= number &&
        num % 2 == number % 2;
*/

/*@
    requires number >= 0;
    ensures \result == (number % 2 == 0);
    assigns \nothing;
*/
bool is_even(long number)
{
    long num = number;

    /*@
        loop invariant is_even_inv(num, number);
        loop assigns num;
        loop variant num;
    */
    while (num >= 2)
    {
        //@ assert num >= 2;
        num = num - 2;
        //@ assert num >= 0;
    }
    //@ assert num == 0 || num == 1;
    return num == 0;
}
