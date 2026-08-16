#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == 1 <==> (((a) == (b) + 1 && (b) + 1 < (c)) ||
        ((a) == (b) && (b) + 1 == (c)) ||
        ((a) == (b) - 1 && (b) - 1 < (c)) ||
        ((a) + 1 == (b) && (a) < (c)) ||
        ((a) + 1 == (b) && (a) + 1 < (c)) ||
        ((a) > (b) && (b) + 1 == (c)) ||
        ((a) > (b) && (a) == (c) - 1));
*/
bool func(int a, int b, int c)
{
    bool answer = false;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    if ((a == b + 1 && b + 1 < c) ||
        (a == b && b + 1 == c) ||
        (a == b - 1 && b - 1 < c) ||
        (a + 1 == b && a < c) ||
        (a + 1 == b && a + 1 < c) ||
        (a > b && b + 1 == c) ||
        (a > b && a == c - 1))
    {
        answer = true;
    }

    //@ assert answer == 1 <==> (((a) == (b) + 1 && (b) + 1 < (c)) ||         ((a) == (b) && (b) + 1 == (c)) ||         ((a) == (b) - 1 && (b) - 1 < (c)) ||         ((a) + 1 == (b) && (a) < (c)) ||         ((a) + 1 == (b) && (a) + 1 < (c)) ||         ((a) > (b) && (b) + 1 == (c)) ||         ((a) > (b) && (a) == (c) - 1));

    return answer;
}
