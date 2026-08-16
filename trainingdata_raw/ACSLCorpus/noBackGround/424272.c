#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == ( (n / 100) > (n % 100) );
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int x;
    unsigned int y;

    //@ assert (1 <= (n) && (n) <= 10000);

    x = n / 100;
    y = n % 100;

    //@ assert x == ((n) / 100);
    //@ assert y == ((n) % 100);

    return x > y;
}
