#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 &&
        0 <= (a) <= 1000);
    ensures \result == (((n) % 500) <= a);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long a)
{
    unsigned long remainder;
    //@ assert (1 <= (n) <= 10000 &&         0 <= (a) <= 1000);
    remainder = n % 500;
    //@ assert remainder == ((n) % 500);
    //@ assert 0 <= remainder < 500;
    //@ assert remainder <= a ==> remainder <= a;
    return remainder <= a;
}
