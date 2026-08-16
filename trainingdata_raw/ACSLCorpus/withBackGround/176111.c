#include <stdbool.h>

/*@
    predicate exactly_one_equal(integer a, integer b, integer c) =
        (a == b && c != a && c != b) ||
        (b == c && a != b && a != c) ||
        (c == a && b != c && b != a);

    lemma cnt_range:
        \forall integer a, b, c, cnt;
        (1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9) &&
        cnt == ((a == b ? 1 : 0) + (b == c ? 1 : 0) + (c == a ? 1 : 0)) ==>
        0 <= cnt <= 3;
*/

/*@
    requires 1 <= a && a <= 9;
    requires 1 <= b && b <= 9;
    requires 1 <= c && c <= 9;
    ensures \result == ((a == b && c != a && c != b) ||
                       (b == c && a != b && a != c) ||
                       (c == a && b != c && b != a));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int cnt = 0;

    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    if (a == b) {
        cnt += 1;
    }
    if (b == c) {
        cnt += 1;
    }
    if (c == a) {
        cnt += 1;
    }

    //@ assert 0 <= cnt <= 3;
    //@ assert cnt == ((a == b ? 1 : 0) + (b == c ? 1 : 0) + (c == a ? 1 : 0));

    return cnt == 1;
}
