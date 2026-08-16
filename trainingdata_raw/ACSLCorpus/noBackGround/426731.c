#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 13 &&
        1 <= (b) && (b) <= 13 &&
        1 <= (c) && (c) <= 13);
    ensures \result == true <==> a + b + c <= 21;
    ensures \result == false <==> a + b + c > 21;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool is_bust;

    sum = a + b + c;
    is_bust = false;

    if (sum > 21)
    {
        is_bust = true;
    }
    else
    {
        is_bust = false;
    }

    //@ assert is_bust == true <==> a + b + c > 21;

    if (is_bust)
    {
        return false;
    }
    else
    {
        return true;
    }
}
