#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((n) + (m)) || \result == ((n) * (m));
    ensures \result >= ((n) + (m));
*/
int func(int n, int m)
{
    int product;
    int sum;
    int result;

    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    //@ assert ((n) * (m)) <= 400;
    //@ assert ((n) + (m)) <= 40;

    product = n * m;
    sum = n + m;

    //@ assert product == ((n) * (m));
    //@ assert sum == ((n) + (m));

    if (product > sum)
    {
        result = product;
        //@ assert result == ((n) * (m));
    }
    else
    {
        result = sum;
        //@ assert result == ((n) + (m));
    }

    //@ assert result >= ((n) + (m));
    //@ assert result == ((n) + (m)) || result == ((n) * (m));
    return result;
}
