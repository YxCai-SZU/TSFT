#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == (n >= 2000 || n % 200 == 0);
    assigns \nothing;
*/
bool func(int n)
{
    bool result;
    int temp;

    if (n < 2000)
    {
        temp = n;
        /*@
            loop invariant 1 <= n <= 100000;
            loop invariant temp <= n;
            loop invariant temp >= 0;
            loop invariant temp % 200 == n % 200;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 200)
        {
            temp -= 200;
        }
        //@ assert temp == n % 200;
        if (temp == 0)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = true;
    }
    //@ assert result == (n >= 2000 || n % 200 == 0);
    return result;
}
