#include <stdbool.h>

/*@
    requires \valid(v+(0..len-1));
    requires len >= 3;
    requires (\forall integer k; 0 <= k < (len) ==> (v)[k] >= 1 && (v)[k] <= 13);
    ensures \result == (v[0] + v[1] + v[2] >= 22);
    assigns \nothing;
*/
bool func(int *v, int len) {
    int total = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant total >= 0;
        loop invariant total <= i * 13;
        loop invariant \forall integer j; 0 <= j < i ==> ((0 <= ((j)) < ((len))) ==> (v)[(j)] >= 1 && (v)[(j)] <= 13);
        loop invariant len >= 3;
        loop invariant (\forall integer k; 0 <= k < (len) ==> (v)[k] >= 1 && (v)[k] <= 13);
        loop invariant i == 0 ==> total == 0;
        loop invariant i == 1 ==> total == v[0];
        loop invariant i == 2 ==> total == v[0] + v[1];
        loop invariant i == 3 ==> total == v[0] + v[1] + v[2];
        loop assigns total, i;
        loop variant 3 - i;
    */
    while (i < 3 && i < len) {
        //@ assert ((0 <= ((i)) < ((len))) ==> (v)[(i)] >= 1 && (v)[(i)] <= 13);
        total += v[i];
        i++;
    }

    //@ assert total == v[0] + v[1] + v[2];
    return total >= 22;
}
