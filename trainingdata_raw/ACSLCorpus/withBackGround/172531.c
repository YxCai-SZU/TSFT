#include <stdbool.h>

/*@
    predicate valid_array(int *p, integer n) =
        n >= 3 && n <= 100 &&
        \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= 20;

    predicate valid_params(integer a, integer b) =
        1 <= a && a < b && b < 20;

    logic integer position(integer h, integer a, integer b) =
        h <= a ? 1 : (h <= b ? 2 : 3);

    lemma count_bounds:
        \forall integer n, integer a, integer b, int *p;
        valid_array(p, n) && valid_params(a, b) ==>
        (\forall integer i; 0 <= i < n ==> position(p[i], a, b) >= 1 && position(p[i], a, b) <= 3);
*/

/*@
    requires 3 <= n && n <= 100;
    requires \valid(p + (0 .. n-1));
    requires valid_array(p, n);
    requires 1 <= a && a < b && b < 20;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int a, int b, int *p) {
    int count = 0;
    int current_position = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant current_position >= 0;
        loop invariant current_position <= 3;
        loop invariant valid_array(p, n);
        loop invariant valid_params(a, b);
        loop assigns i, count, current_position;
        loop variant n - i;
    */
    while (i < n) {
        int h = p[i];
        //@ assert h >= 1 && h <= 20;
        
        if (h <= a) {
            current_position = 1;
        } else if (h <= b) {
            current_position = 2;
        } else {
            current_position = 3;
        }
        //@ assert current_position >= 1 && current_position <= 3;
        
        if (current_position < 3) {
            count += 1;
        }
        //@ assert count >= 0 && count <= i+1;
        
        i += 1;
    }
    //@ assert count >= 0 && count <= n;
    return count;
}
