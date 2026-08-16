#include <stdbool.h>

/*@
    predicate nondecreasing_seq(int *a, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> a[i] <= a[i + 1];
 */

/*@
    requires \valid(a + (0..len-1));
    requires len >= 1;
    assigns \nothing;
    ensures \result == 1 <==> nondecreasing_seq(a, len);
 */
bool nondecreasing_sequence(int *a, int len) {
    int i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i - 1 ==> a[j] <= a[j + 1];
        loop assigns i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert 0 <= i - 1 < i < len;
        if (a[i] < a[i - 1]) {
            //@ assert !nondecreasing_seq(a, len);
            return false;
        }
        i++;
    }
    //@ assert nondecreasing_seq(a, len);
    return true;
}

int main() {
    return 0;
}
