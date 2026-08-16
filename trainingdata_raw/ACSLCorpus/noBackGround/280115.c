#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (500 * k >= x);
*/
bool func(int k, int x)
{
    int product;
    bool result;

    //@ ghost int k_spec = k;
    //@ ghost int x_spec = x;

    // Implementing the mathematical operation 500 * k
    if (k >= 0)
    {
        product = 500 * k;
        //@ assert ((k_spec) >= 0 ==> (product) == 500 * (k_spec) &&         (k_spec) < 0 ==> (product) == -500 * (k_spec));
    }
    else
    {
        product = -500 * k;
        //@ assert ((k_spec) >= 0 ==> (product) == 500 * (k_spec) &&         (k_spec) < 0 ==> (product) == -500 * (k_spec));
    }

    // Implementing the comparison product >= x
    if (product >= x)
    {
        result = true;
        //@ assert result == (product >= x_spec);
    }
    else
    {
        result = false;
        //@ assert result == (product >= x_spec);
    }

    // Final verification of postcondition
    //@ assert result == (500 * k_spec >= x_spec);
    return result;
}
