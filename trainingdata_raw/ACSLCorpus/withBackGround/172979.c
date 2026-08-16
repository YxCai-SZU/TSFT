#include <stdbool.h>

/*@
    predicate non_negative(integer n) = n >= 0;
    predicate upper_bound(integer n) = n <= n + 5;
*/

/*@
    lemma check_bounds:
        \forall integer n; non_negative(n) ==> upper_bound(n);
*/

/*@
    requires n >= 0;
    ensures \result == n + 5;
    assigns \nothing;
*/
int add_five(int n) {
    int result;
    //@ assert n >= 0;
    result = n + 5;
    //@ assert result == n + 5;
    return result;
}

int main() {
    int x = 3;
    int y = add_five(x);
    //@ assert y == 8;
    return 0;
}
