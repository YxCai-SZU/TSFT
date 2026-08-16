#include <stdbool.h>

/*@
    requires ((a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 &&
        (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int diff;

    //@ assert e > a;
    diff = e - a;
    //@ assert diff <= 123;
    result = (diff <= k);
    return result;
}
