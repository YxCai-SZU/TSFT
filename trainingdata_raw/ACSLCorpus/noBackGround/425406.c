#include <stdbool.h>

/*@
    requires a > -2147483648 && b > -2147483648 && c > -2147483648;
    requires a < 2147483647 && b < 2147483647 && c < 2147483647;
    ensures \result == true <==> a < b && b < c;
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool check;
    check = true;

    if (a >= b)
    {
        check = false;
    }
    if (b >= c)
    {
        check = false;
    }

    //@ assert check == true <==> a < b && b < c;

    return check;
}
