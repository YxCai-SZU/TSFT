#include <stdbool.h>

/*@
    requires a <= b;
    requires a >= -0x8000000000000000;
    requires b <= 0x7FFFFFFFFFFFFFFF;
    requires c >= -0x8000000000000000;
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool is_between(long long a, long long b, long long c)
{
    //@ assert a <= b;
    //@ assert a >= -0x8000000000000000;
    //@ assert b <= 0x7FFFFFFFFFFFFFFF;
    //@ assert c >= -0x8000000000000000;
    
    return a <= c && c <= b;
}
