#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer x) =
        a >= 0 && a <= 100 &&
        b >= 0 && b <= 100 &&
        x >= 0 && x <= 100 &&
        a + b >= x;

    lemma sum_bound:
        \forall integer a, b;
        a >= 0 && a <= 100 && b >= 0 && b <= 100 ==> a + b <= 200;

    lemma sum_ge_x:
        \forall integer a, b, x;
        valid_range(a, b, x) ==> a + b >= x;
*/

/*@
    requires \valid(a + (0..2));
    requires a[0] >= 0 && a[0] <= 100;
    requires a[1] >= 0 && a[1] <= 100;
    requires a[2] >= 0 && a[2] <= 100;
    requires a[0] + a[1] >= a[2];
    ensures \result == (a[0] + a[1] == a[2]);
    assigns \nothing;
*/
bool func(unsigned long long a[3]) {
    unsigned long long A;
    unsigned long long B;
    unsigned long long X;
    bool result;

    A = a[0];
    B = a[1];
    X = a[2];

    //@ assert A + B <= 200;
    //@ assert A + B >= X;

    result = (A + B == X);
    return result;
}
