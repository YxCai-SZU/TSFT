#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100 && (a) + (b) + (c) > 0);
    ensures \result <==> (((a) >= (c) && (c) >= (b)) || ((a) <= (c) && (c) <= (b)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a + b + c > 0;
    return (a >= c && c >= b) || (a <= c && c <= b);
}
