#include <stdbool.h>

/*@
    requires a <= 10000 && b <= 10000 && c <= 10000;
    ensures \result == ((a + b) >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int sum;
    bool result;

    /*@
        assert a <= 10000;
    */
    /*@
        assert b <= 10000;
    */
    /*@
        assert a + b <= 20000;
    */

    sum = a + b;
    result = (sum >= c);
    return result;
}
