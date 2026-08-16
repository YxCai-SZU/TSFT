#include <stddef.h>
/*@
    predicate valid_array(int *a, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] && a[i] <= 5 &&
        \exists integer i; 0 <= i < len && a[i] == 0;

    lemma exists_zero_in_array:
        \forall int *a, integer len; valid_array(a, len) ==>
            \exists integer i; 0 <= i < len && a[i] == 0;
*/

/*@
    requires \valid(a + (0 .. 4));
    requires valid_array(a, 5);
    ensures 1 <= \result && \result <= 5;
    ensures a[\result - 1] == 0;
    ensures \forall integer i; 0 <= i < 5 && i != \result - 1 ==> 1 <= a[i] && a[i] <= 5;
*/
unsigned int func(int *a) {
    unsigned int i;
    i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant valid_array(a, 5);
        loop invariant \forall integer k; 0 <= k < i ==> 1 <= a[k] && a[k] <= 5;
        loop invariant i > 0 ==> \exists integer k; 0 <= k < i && a[k] == 0;
        loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (a[i] == 0) {
            //@ assert a[i] == 0;
            return i + 1;
        }
        //@ assert a[i] != 0;
        i += 1;
    }
    return 0;
}
