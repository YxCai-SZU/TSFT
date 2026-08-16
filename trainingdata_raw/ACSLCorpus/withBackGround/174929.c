#include <stdint.h>

/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && b == c;

    predicate two_equal(integer a, integer b, integer c) =
        a == b || b == c || a == c;

    predicate all_different(integer a, integer b, integer c) =
        a != b && b != c && a != c;

    lemma answer_one_implies_all_equal:
        \forall integer a,b,c;
        (1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= c && c <= 100) ==>
        (a == b && b == c) ==> all_equal(a,b,c);

    lemma answer_two_implies_two_equal:
        \forall integer a,b,c;
        (1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= c && c <= 100) ==>
        (a == b || b == c || a == c) ==> two_equal(a,b,c);

    lemma answer_three_implies_all_different:
        \forall integer a,b,c;
        (1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= c && c <= 100) ==>
        (a != b && b != c && a != c) ==> all_different(a,b,c);
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> a == b && b == c;
    ensures \result == 2 ==> (a == b || b == c || a == c);
    ensures \result == 3 ==> a != b && b != c && a != c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t answer;

    if (a == b && b == c) {
        answer = 1;
        //@ assert a == b && b == c;
    } else if (a == b || b == c || a == c) {
        answer = 2;
        //@ assert a == b || b == c || a == c;
    } else {
        answer = 3;
        //@ assert a != b && b != c && a != c;
    }

    return answer;
}
