#include <stdbool.h>

/*@ requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a < c) == (c < b));
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a < c && c < b ==> (a < c) == (c < b);
    result = (a < c) == (c < b);
    return result;
}
