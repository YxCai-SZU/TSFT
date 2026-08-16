#include <stddef.h>
#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) < 20);
    requires \valid(p + (0 .. n-1));
    requires (\forall integer k; 0 <= k < (n) ==> 1 <= (p)[k] && (p)[k] <= 20);
    ensures \result >= 0;
    ensures \result <= n;
*/
int64_t func(int64_t n, int64_t a, int64_t b, int64_t *p) {
    int64_t count[3];
    int64_t i;
    int64_t min_count;
    int64_t j;
    
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant count[0] >= 0 && count[0] <= i;
        loop invariant count[1] >= 0 && count[1] <= i;
        loop invariant count[2] >= 0 && count[2] <= i;
        loop invariant \forall integer k; 0 <= k < i ==>
            (p[k] <= a ==> count[0] >= 1) &&
            (p[k] <= b && p[k] > a ==> count[1] >= 1) &&
            (p[k] > b ==> count[2] >= 1);
        loop assigns i, count[0], count[1], count[2];
        loop variant n - i;
    */
    while (i < n) {
        int64_t pi = p[i];
        if (pi <= a) {
            //@ assert pi <= a;
            count[0] = count[0] + 1;
        } else if (pi <= b) {
            //@ assert pi > a && pi <= b;
            count[1] = count[1] + 1;
        } else {
            //@ assert pi > b;
            count[2] = count[2] + 1;
        }
        i = i + 1;
    }
    
    min_count = count[0];
    j = 1;
    /*@
        loop invariant 0 <= j <= 3;
        loop invariant min_count >= 0;
        loop invariant min_count <= n;
        loop invariant \forall integer k; 0 <= k < j ==> min_count <= count[k];
        loop assigns j, min_count;
        loop variant 3 - j;
    */
    while (j < 3) {
        if (min_count > count[j]) {
            min_count = count[j];
        }
        j = j + 1;
    }
    
    //@ assert min_count >= 0;
    //@ assert min_count <= n;
    return min_count;
}
