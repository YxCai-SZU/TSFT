#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    requires a == (long long)a;
    requires b == (long long)b;
    requires c == (long long)c;
    ensures \result == (b - a == c - b);
*/
bool func(long long a, long long b, long long c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert a == (long long)a;
    //@ assert b == (long long)b;
    //@ assert c == (long long)c;
    
    return b - a == c - b;
}
