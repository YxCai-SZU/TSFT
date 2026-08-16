#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == ((((a) == (b) + 1 && (c) == (b) - 1) ? 1 :
        ((a) == (b) - 1 && (c) == (b) + 1) ? 1 :
        ((a) == (c) + 1 && (b) == (c) - 1) ? 1 :
        ((a) == (c) - 1 && (b) == (c) + 1) ? 1 :
        ((b) == (a) + 1 && (c) == (a) - 1) ? 1 :
        ((b) == (a) - 1 && (c) == (a) + 1) ? 1 : 0) == 1);
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    //@ assert 0 <= b - 1 <= 8;
    result = (a == b + 1 && c == b - 1) || (a == b - 1 && c == b + 1) ||
             (a == c + 1 && b == c - 1) || (a == c - 1 && b == c + 1) ||
             (b == a + 1 && c == a - 1) || (b == a - 1 && c == a + 1);

    return result;
}
