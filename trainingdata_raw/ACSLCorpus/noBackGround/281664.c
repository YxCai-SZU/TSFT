#include <stdbool.h>

/*@
    requires 1 <= n <= 1000000;
    ensures \result == (n >= 2000 && n % 2000 == 0);
    assigns \nothing;
*/
bool func(int n)
{
    if (n < 2000)
    {
        return false;
    }

    int temp = n;

    /*@
        loop invariant 1 <= n <= 1000000;
        loop invariant temp <= n;
        loop invariant temp >= 0;
        loop invariant temp % 2000 == n % 2000;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2000)
    {
        temp -= 2000;
    }

    //@ assert temp == n % 2000;
    return temp == 0;
}
