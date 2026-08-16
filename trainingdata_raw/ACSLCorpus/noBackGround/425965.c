#include <stdbool.h>

/*@
    requires (0 <= (a) <= 123 &&
        0 <= (b) <= 123 &&
        0 <= (c) <= 123 &&
        0 <= (d) <= 123 &&
        0 <= (e) <= 123 &&
        0 <= (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    //@ assert (0 <= (a) <= 123 &&         0 <= (b) <= 123 &&         0 <= (c) <= 123 &&         0 <= (d) <= 123 &&         0 <= (e) <= 123 &&         0 <= (k) <= 123 &&         (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    return (e - a) <= k;
}
