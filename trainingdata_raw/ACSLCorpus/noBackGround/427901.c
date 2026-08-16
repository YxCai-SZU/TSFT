#include <stdbool.h>

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    requires 1 <= c <= 20;
    requires 1 <= d <= 20;
    ensures \result == (a > b && b > c && c > d);
    assigns \nothing;
 */
bool func(int a, int b, int c, int d)
{
    bool ans = true;

    //@ assert ans == true;

    if (a <= b)
    {
        ans = false;
        //@ assert ans == false;
    }
    else if (b <= c)
    {
        ans = false;
        //@ assert ans == false;
    }
    else if (c <= d)
    {
        ans = false;
        //@ assert ans == false;
    }

    //@ assert ans == (a > b && b > c && c > d);
    return ans;
}
