#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == true <==> a <= b;
    assigns \nothing;
*/
bool func(int a, int b)
{
    int x;
    int y;
    bool result;

    x = a;
    y = b;

    //@ assert x == a;
    //@ assert y == b;

    result = (x <= y);
    return result;
}
