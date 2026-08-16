#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == true <==> (n % 2 == 0 || n % 3 == 0 || n % 5 == 0);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool result;

    a = n % 2;
    b = n % 3;
    c = n % 5;

    if (a == 0 || b == 0 || c == 0)
    {
        //@ assert a == 0 || b == 0 || c == 0;
        result = true;
    }
    else
    {
        //@ assert a != 0 && b != 0 && c != 0;
        result = false;
    }

    return result;
}
