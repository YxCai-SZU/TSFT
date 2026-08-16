#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
*/
bool func(int n, int m)
{
    bool has_queen;
    bool is_square;
    bool result;

    has_queen = (n == m);
    is_square = (n == m);

    //@ assert is_square ==> has_queen;

    result = has_queen && is_square;
    return result;
}
