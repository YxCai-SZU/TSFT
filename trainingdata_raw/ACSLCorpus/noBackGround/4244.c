#include <stdbool.h>

/*@
    requires a <= b;
    requires a >= -0x7FFFFFFFFFFFFFFF && b <= 0x7FFFFFFFFFFFFFFF;
    requires c >= -0x7FFFFFFFFFFFFFFF && c <= 0x7FFFFFFFFFFFFFFF;
    ensures \result <==> ((a) <= (c) && (c) <= (b));
*/
bool is_between(long long a, long long b, long long c)
{
    //@ assert a <= b;
    //@ assert a >= -0x7FFFFFFFFFFFFFFF && b <= 0x7FFFFFFFFFFFFFFF;
    //@ assert c >= -0x7FFFFFFFFFFFFFFF && c <= 0x7FFFFFFFFFFFFFFF;
    
    return a <= c && c <= b;
}
