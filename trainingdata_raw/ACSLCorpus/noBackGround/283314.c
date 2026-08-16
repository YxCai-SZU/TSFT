#include <limits.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures \result == ((a) + (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int product;
    int result;

    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);
    //@ assert ((a) * (b)) <= 400;

    sum = a + b;
    product = a * b;

    if (sum > product)
    {
        result = sum;
    }
    else
    {
        result = product;
    }

    //@ assert result == ((a) + (b)) || result == ((a) * (b));
    //@ assert result >= ((a) + (b));
    //@ assert result >= ((a) * (b));

    return result;
}
