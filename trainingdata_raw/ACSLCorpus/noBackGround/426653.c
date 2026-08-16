#include <limits.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures ((\result) + (a) + (b) == 6 && 1 <= (\result) <= 3);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int result;
    int new_result;

    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    //@ assert ((a) != (b));

    sum = a + b;
    result = 6 - sum;

    if (result < 1 || result > 3)
    {
        new_result = 0;

        if (a == 1)
        {
            if (b == 2)
            {
                new_result = 3;
            }
            else
            {
                new_result = 2;
            }
        }
        else if (a == 2)
        {
            if (b == 1)
            {
                new_result = 3;
            }
            else
            {
                new_result = 1;
            }
        }
        else
        {
            if (b == 1)
            {
                new_result = 2;
            }
            else
            {
                new_result = 1;
            }
        }

        result = new_result;
    }

    //@ assert ((result) + (a) + (b) == 6 && 1 <= (result) <= 3);
    return result;
}
