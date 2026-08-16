#include <stdbool.h>
/*@
    requires \valid(a+(0..4));
    requires ((5) == 5 &&
        \forall integer k; 0 <= k < (5) ==> (1 <= (a)[k] && (a)[k] <= 5) &&
        \exists integer k; 0 <= k < (5) && (a)[k] == 0);
    ensures 1 <= \result && \result <= 5;
    ensures a[\result - 1] == 0;
    assigns \nothing;
*/
int find_j(int *a) {
    int i;
    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
        \forall integer k; 0 <= k < (5) ==> (1 <= (a)[k] && (a)[k] <= 5) &&
        \exists integer k; 0 <= k < (5) && (a)[k] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (a)[k] != 0);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (a[i] == 0) {
            //@ assert a[i] == 0;
            return i + 1;
        }
        //@ assert a[i] != 0;
        i = i + 1;
    }
    //@ assert i == 5;
    //@ assert (\forall integer k; 0 <= k < (5) ==> (a)[k] != 0);
    //@ assert \exists integer k; 0 <= k < 5 && a[k] == 0;
    return 0;
}
