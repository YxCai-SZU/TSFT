#include <stdbool.h>

/*@
    requires a < 0x80000000;
    requires b < 0x80000000;
    requires c < 0x80000000;
    requires d < 0x80000000;
    requires e < 0x80000000;
    requires k < 0x80000000;
    requires a <= b;
    requires b <= c;
    requires c <= d;
    requires d <= e;
    ensures \result == true <==> (((b) - (a) <= (k) ? 1 : 0) + ((c) - (a) <= (k) ? 1 : 0) + ((d) - (a) <= (k) ? 1 : 0) + ((e) - (a) <= (k) ? 1 : 0)) > 0;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    //@ assert ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
    return (b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k);
}
