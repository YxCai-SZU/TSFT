#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    lemma answer_lemma:
        \forall integer a, b, c, answer;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        (answer == (a < b && b < c)) ==>
        answer == (a < b && b < c);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool answer = false;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    if (a < b)
    {
        if (b < c)
        {
            answer = true;
        }
        else
        {
            answer = false;
        }
    }
    else
    {
        answer = false;
    }

    //@ assert answer == (a < b && b < c);
    return answer;
}
