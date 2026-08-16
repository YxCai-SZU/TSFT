#include <stdbool.h>

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((1 <= ((a)) && ((a)) <= 10000) && (1 <= ((b)) && ((b)) <= 10000) ==> (a) * (b) <= 10000 * 10000);
    
    return (a * b) % 2 == 0;
}
