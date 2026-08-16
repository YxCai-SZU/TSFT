#include <stdint.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        (a == b && b == c) ? a :
        (a != b && b == c) ? a :
        (a == b && b != c) ? c :
        (a == c && b != c) ? b : 0;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures (a == b && b == c) ==> \result == a;
    ensures (a != b && b == c) ==> \result == a;
    ensures (a == b && b != c) ==> \result == c;
    ensures (a == c && b != c) ==> \result == b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t answer = 0;

    if (a == b)
    {
        answer = c;
    }
    else if (b == c)
    {
        answer = a;
    }
    else if (a == c)
    {
        answer = b;
    }

    //@ assert (a == b && b == c) ==> answer == a;
    //@ assert (a != b && b == c) ==> answer == a;
    //@ assert (a == b && b != c) ==> answer == c;
    //@ assert (a == c && b != c) ==> answer == b;

    return answer;
}

/*@
    lemma func_correctness:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            func_result(a, b, c) == (
                (a == b && b == c) ? a :
                (a != b && b == c) ? a :
                (a == b && b != c) ? c :
                (a == c && b != c) ? b : 0
            );
*/
