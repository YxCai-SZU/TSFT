#include <stdbool.h>

/*@
    requires a <= b;
    requires (-0x8000000000000000 <= (a) && (a) <= 0x7FFFFFFFFFFFFFFF);
    requires (-0x8000000000000000 <= (b) && (b) <= 0x7FFFFFFFFFFFFFFF);
    requires (-0x8000000000000000 <= (c) && (c) <= 0x7FFFFFFFFFFFFFFF);
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    bool result;
    //@ assert a <= b;
    result = (a <= c && c <= b);
    //@ assert result == (a <= c && c <= b);
    return result;
}

/*@
    requires a <= b;
    requires (-0x8000000000000000 <= (a) && (a) <= 0x7FFFFFFFFFFFFFFF);
    requires (-0x8000000000000000 <= (b) && (b) <= 0x7FFFFFFFFFFFFFFF);
    requires (-0x8000000000000000 <= (c) && (c) <= 0x7FFFFFFFFFFFFFFF);
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func2(long long a, long long b, long long c)
{
    bool result;
    //@ assert a <= b;
    result = (c >= a && c <= b);
    //@ assert result == (c >= a && c <= b);
    return result;
}
