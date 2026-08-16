#include <stdbool.h>

/*@ requires (1 <= (n) <= 10000) && (1 <= (m) <= 10000);
    ensures \result == (n == m);
    assigns \nothing;
 */
bool func(unsigned int n, unsigned int m)
{
    //@ assert (1 <= (n) <= 10000);
    //@ assert (1 <= (m) <= 10000);
    if (n == m) {
        return true;
    } else {
        return false;
    }
}

/*@ requires (1 <= (n) <= 10000) && (1 <= (m) <= 10000);
    ensures \result == (n == m);
    assigns \nothing;
 */
bool func2(unsigned int n, unsigned int m)
{
    //@ assert (1 <= (n) <= 10000);
    //@ assert (1 <= (m) <= 10000);
    return n == m;
}
