#include <stdbool.h>
/*@
    predicate x_in_range(integer x) = 1 <= x <= 100000;
    predicate i_in_range(integer i) = 1 <= i <= 1001;
    predicate a_bounds(integer a, integer i) = a >= 0 && a <= i - 1;
    predicate a_final_bounds(integer a) = a >= 0 && a <= 1000;
    predicate b_bounds(integer b, integer i) = b >= 0 && b <= i - 1;
*/

/*@
    requires x_in_range(x);
    ensures \result == 0 || \result == 1;
*/
int func(unsigned int x) {
    int a;
    int b;
    unsigned int i;
    int ans;

    a = 0;
    i = 1;
    /*@
        loop invariant x_in_range(x);
        loop invariant i_in_range(i);
        loop invariant a_bounds(a, i);
        loop assigns a, i;
        loop variant 1001 - i;
    */
    while (i < 1001) {
        //@ assert x_in_range(x);
        if (x >= i * 100) {
            a = a + 1;
        }
        i = i + 1;
    }
    //@ assert a_final_bounds(a);

    b = 0;
    i = 1;
    /*@
        loop invariant x_in_range(x);
        loop invariant i_in_range(i);
        loop invariant a_final_bounds(a);
        loop invariant b_bounds(b, i);
        loop assigns b, i;
        loop variant 1001 - i;
    */
    while (i < 1001) {
        //@ assert x_in_range(x);
        if (x == i * 100) {
            b = b + 1;
        }
        i = i + 1;
    }

    if (a == b) {
        ans = 1;
    } else {
        ans = 0;
    }
    //@ assert ans == 0 || ans == 1;
    return ans;
}
