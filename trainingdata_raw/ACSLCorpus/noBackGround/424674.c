#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result <==> (((a) == (b) && (b) != (c)) ||
        ((a) != (b) && (a) == (c)) ||
        ((a) != (b) && (a) != (c) && (b) == (c)));
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    return (a == b && b != c) || (a != b && a == c) || (a != b && a != c && b == c);
}
