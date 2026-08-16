#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)));
 */
bool func(int a, int b, int c)
{
    bool answer = false;

    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    if (a == b)
    {
        answer = (a != c);
        //@ assert answer == (a == b && a != c);
    }
    else if (a == c)
    {
        answer = (a != b);
        //@ assert answer == (a == c && a != b);
    }
    else if (b == c)
    {
        answer = (a != b);
        //@ assert answer == (b == c && a != b);
    }

    //@ assert answer == true <==> (((a) == (b) && (a) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (a) != (b)));
    return answer;
}
