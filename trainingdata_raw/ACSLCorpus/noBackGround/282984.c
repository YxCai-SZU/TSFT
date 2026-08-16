#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures 0 <= \result <= x;
    assigns \nothing;
*/
int func(int x)
{
    int count = 0;
    int i = 1;

    /*@
        loop invariant 1 <= i <= x + 1;
        loop invariant 0 <= count <= i - 1;
        loop invariant 1 <= x <= 100000;
        loop assigns count, i;
        loop variant x - i + 1;
    */
    while (i <= x)
    {
        int temp1 = i;
        bool is_divisible_by_3;

        /*@
            loop invariant 0 <= temp1 <= i;
            loop invariant 1 <= i <= x;
            loop assigns temp1;
            loop variant temp1;
        */
        while (temp1 >= 3)
        {
            temp1 -= 3;
        }
        is_divisible_by_3 = (temp1 == 0);

        int temp2 = i;
        bool is_divisible_by_5;

        /*@
            loop invariant 0 <= temp2 <= i;
            loop invariant 1 <= i <= x;
            loop assigns temp2;
            loop variant temp2;
        */
        while (temp2 >= 5)
        {
            temp2 -= 5;
        }
        is_divisible_by_5 = (temp2 == 0);

        if (!is_divisible_by_3 && !is_divisible_by_5)
        {
            //@ assert count >= 0 && count < i;
            count += 1;
            //@ assert count >= 1 && count <= i;
        }

        i += 1;
        //@ assert count <= i - 1;
    }

    //@ assert 0 <= count <= x;
    return count;
}
