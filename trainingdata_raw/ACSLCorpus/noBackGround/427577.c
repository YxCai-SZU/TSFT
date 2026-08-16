#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100 &&
        (a) != (b) && (a) != (c) && (b) != (c));
    ensures \result <==> ((((a)) + ((b))) > (c) &&
        (((a)) + ((c))) > (b) &&
        (((b)) + ((c))) > (a));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert a != b && a != c && b != c;

    result = (a + b > c) && (a + c > b) && (b + c > a);
    return result;
}
