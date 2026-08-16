#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000 && 0 <= (a) && (a) <= 100);
    ensures \result == 1 <==> ((n) % 500 <= (a));
    assigns \nothing;
*/
bool func(int n, int a)
{
    int remainder;
    bool result;

    //@ assert n <= 10000;
    remainder = n % 500;
    result = remainder <= a;

    return result;
}
