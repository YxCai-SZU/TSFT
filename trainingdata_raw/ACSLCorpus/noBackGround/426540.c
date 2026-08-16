#include <stdbool.h>

/*@
    requires 100 <= n <= 999;
    ensures \result == true <==> (((n) / 100) == 7 ||
        (((n) / 10) % 10) == 7 ||
        ((n) % 10) == 7);
    assigns \nothing;
*/
bool func(int n)
{
    int a0;
    int a1;
    int a2;
    int c;

    a0 = n / 100;
    a1 = (n / 10) % 10;
    a2 = n % 10;
    c = 0;

    if (a0 == 7)
    {
        c += 1;
    }
    if (a1 == 7)
    {
        c += 1;
    }
    if (a2 == 7)
    {
        c += 1;
    }

    //@ assert c > 0 <==> (((n) / 100) == 7 ||         (((n) / 10) % 10) == 7 ||         ((n) % 10) == 7);

    return c > 0;
}
