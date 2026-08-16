#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (a + b >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;
    unsigned int sum;

    //@ assert (0 <= (a) <= 100 && 0 <= (b) <= 100 ==> 0 <= (a) + (b) <= 200);
    sum = a + b;
    result = (sum >= c);
    return result;
}
