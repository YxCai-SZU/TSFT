#include <stdbool.h>

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    ensures \result == true <==> (a * 3 + b) >= 100;
    ensures \result == false <==> (a * 3 + b) < 100;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int product;
    unsigned int sum;
    bool result;

    product = a * 3;
    sum = product + b;

    if (sum >= 100)
    {
        //@ assert ((sum) == (a) * 3 + (b) && (sum) >= 100);
        result = true;
    }
    else
    {
        //@ assert ((sum) == (a) * 3 + (b) && (sum) < 100);
        result = false;
    }

    return result;
}
