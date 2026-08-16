#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == true <==> a + b + c >= 22;
    ensures \result == false <==> a + b + c < 22;
*/
bool func(int a, int b, int c)
{
    int sum;
    bool result;

    sum = a + b + c;

    if (sum >= 22)
    {
        //@ assert sum >= 22;
        result = true;
    }
    else
    {
        //@ assert sum < 22;
        result = false;
    }

    return result;
}
