#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires a != b;
    ensures \result == true <==> (((c) > (a) && (c) < (b)) || ((c) < (a) && (c) > (b)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    //@ assert a != b;
    return (c > a && c < b) || (c < a && c > b);
}
