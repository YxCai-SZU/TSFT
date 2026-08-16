#include <stdbool.h>
/*@
    requires \valid(list1 + (0 .. len-1));
    requires len > 0;
    requires (\forall integer i; 0 <= i < (len) ==> (list1)[i] < 0);
    ensures \result >= -2147483648;
    ensures \forall integer k; 0 <= k < len ==> \result >= list1[k];
*/
int largest_neg(int *list1, int len) {
    int max;
    int i;
    //@ assert len > 0;
    max = list1[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer i; 0 <= i < (len) ==> (list1)[i] < 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max) >= (list1)[k]);
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer i; 0 <= i < (len) ==> (list1)[i] < 0);
        if (list1[i] > max) {
            max = list1[i];
        }
        i = i + 1;
        //@ assert (\forall integer k; 0 <= k < (i) ==> (max) >= (list1)[k]);
    }
    //@ assert (\forall integer k; 0 <= k < (len) ==> (max) >= (list1)[k]);
    return max;
}
