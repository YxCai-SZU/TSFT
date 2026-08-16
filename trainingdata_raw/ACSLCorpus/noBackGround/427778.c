#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n % 10 == 9 || n / 10 == 9);
    assigns \nothing;
*/
bool func(int n)
{
    //@ assert (10 <= (n) && (n) <= 99);
    return (n % 10 == 9) || (n / 10 == 9);
}
