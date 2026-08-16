#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer func_spec(integer a, integer b, integer c) =
        (a < b ? b - a : 0) +
        (b < c ? c - b : 0) +
        (c < a ? a - c : 0);

    lemma func_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            0 <= func_spec(a, b, c) <= a + b + c;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures \result == func_spec(a, b, c);
*/
int func(int a, int b, int c)
{
    int answer = 0;

    //@ assert answer >= 0;
    //@ assert answer <= a + b + c;

    if (a < b)
    {
        answer += b - a;
        //@ assert answer >= b - a;
        //@ assert answer <= a + b + c;
    }

    if (b < c)
    {
        answer += c - b;
        //@ assert answer >= (a < b ? b - a : 0) + (c - b);
        //@ assert answer <= a + b + c;
    }

    if (c < a)
    {
        answer += a - c;
        //@ assert answer >= (a < b ? b - a : 0) + (b < c ? c - b : 0) + (a - c);
        //@ assert answer <= a + b + c;
    }

    //@ assert answer >= 0;
    //@ assert answer <= a + b + c;
    //@ assert answer == func_spec(a, b, c);

    return answer;
}
