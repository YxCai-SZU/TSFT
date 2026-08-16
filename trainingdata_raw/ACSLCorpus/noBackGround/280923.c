#include <stdbool.h>

/*@
    requires 1 <= x <= 9;
    ensures \result == (x == 7 || x == 5 || x == 3);
    assigns \nothing;
*/
bool func(unsigned long x)
{
    unsigned long good_values[3] = {7, 5, 3};
    int i = 0;
    bool result = false;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> x != good_values[k];
        loop invariant result == false;
        loop assigns i, result;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        if (x == good_values[i])
        {
            result = true;
            break;
        }
        i = i + 1;
    }

    //@ assert result == (x == 7 || x == 5 || x == 3);
    return result;
}
