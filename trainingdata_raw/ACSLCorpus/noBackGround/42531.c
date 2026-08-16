#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == ((n / 2) >= 5 || (n % 2) == 1);
*/
bool func(unsigned long n)
{
    unsigned long half;
    unsigned long remainder;
    bool result;

    half = n / 2;
    remainder = n % 2;

    //@ assert ((half) == (n) / 2);
    //@ assert ((remainder) == (n) % 2);

    result = (half >= 5) || (remainder == 1);

    //@ assert ((result) == (((n) / 2) >= 5 || ((n) % 2) == 1));
    return result;
}
