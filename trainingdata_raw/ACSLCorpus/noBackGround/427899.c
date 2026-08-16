#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result == true <==> (a * b) <= c;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    result = (a * b) <= c;
    return result;
}
