#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == true <==> (((n) / 10 == 9) || ((n) % 10 == 9));
    assigns \nothing;
*/
bool func(int n)
{
    int a0;
    int a1;
    bool result;

    a0 = n / 10;
    a1 = n % 10;

    //@ assert a0 == n / 10;
    //@ assert a1 == n % 10;

    result = (a0 == 9) || (a1 == 9);
    return result;
}
