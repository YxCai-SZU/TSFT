#include <stdbool.h>
/*@
    requires \valid(v+(0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 20 &&
        1 <= (v)[2] <= 2000);
    ensures \result >= 0;
    ensures \result <= v[2];
    assigns \nothing;
*/
int func(int *v)
{
    int result;
    int product;

    //@ assert 1 <= v[0] <= 100;
    //@ assert 1 <= v[1] <= 20;
    //@ assert 1 <= v[2] <= 2000;
    //@ assert v[0] * v[1] <= 2000;

    product = v[0] * v[1];
    if (product <= v[2])
    {
        result = product;
    }
    else
    {
        result = v[2];
    }

    //@ assert result >= 0;
    //@ assert result <= v[2];
    return result;
}
