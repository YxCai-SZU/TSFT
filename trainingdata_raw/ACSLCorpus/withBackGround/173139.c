#include <stdbool.h>

/*@
    predicate is_divisible_by_3(integer a) = a % 3 == 0;
*/

/*@
    requires a < 0x10000000;
    ensures \result == true <==> a % 3 == 0;
    assigns \nothing;
*/
bool func(unsigned int a)
{
    bool is_divisible_by_3 = false;
    unsigned int temp_a = a;

    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 3 == a % 3;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 3)
    {
        //@ assert temp_a >= 3;
        temp_a -= 3;
    }

    if (temp_a == 0)
    {
        is_divisible_by_3 = true;
    }

    //@ assert is_divisible_by_3 == (a % 3 == 0);
    return is_divisible_by_3;
}
