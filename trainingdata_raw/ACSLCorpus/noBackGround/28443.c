#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000 && 1 <= (a) <= (b) <= 1000);
    ensures \result == 1 <==> ((a) == (b) || (a) % (k) == 0 || ((a) / (k) < (b) / (k)));
    assigns \nothing;
 */
int func(int k, int a, int b)
{
    int result;

    if (a == b)
    {
        //@ assert a == b;
        result = 1;
    }
    else if (a % k == 0)
    {
        //@ assert a % k == 0;
        result = 1;
    }
    else if (a / k < b / k)
    {
        //@ assert a / k < b / k;
        result = 1;
    }
    else
    {
        //@ assert a != b && a % k != 0 && a / k >= b / k;
        result = 0;
    }

    return result;
}
