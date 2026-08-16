#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13);
    requires (1 <= (b) <= 13);
    requires (1 <= (c) <= 13);
    ensures \result == true <==> (a + b + c >= 22);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    unsigned int sum;

    result = false;
    sum = a + b + c;

    if (sum >= 22)
    {
        result = true;
    }

    //@ assert result == true <==> (a + b + c >= 22);
    return result;
}
