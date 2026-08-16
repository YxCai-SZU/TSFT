#include <stdbool.h>
#include <stddef.h>

/*@
    requires (\valid((s)+(0..4)));
    requires \forall integer i; 0 <= i < 5 ==> (0 <= (s)[(i)] <= 123);
    requires (\valid((a)+(0..4)));
    requires \forall integer i; 0 <= i < 5 ==> (0 <= (a)[(i)] <= 123);
    requires \forall integer i, j; 0 <= i < j < 5 ==> ((s)[(i)] != (s)[(j)]);
    ensures 0 <= \result <= 5;
    assigns \nothing;
 */
int func(long long *s, long long *a) {
    int ans = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 0 <= ans <= (int)i;
        loop invariant (\valid((s)+(0..4)));
        loop invariant \forall integer k; 0 <= k < 5 ==> (0 <= (s)[(k)] <= 123);
        loop invariant (\valid((a)+(0..4)));
        loop invariant \forall integer k; 0 <= k < 5 ==> (0 <= (a)[(k)] <= 123);
        loop invariant \forall integer k, l; 0 <= k < l < 5 ==> ((s)[(k)] != (s)[(l)]);
        loop assigns i, ans;
        loop variant 5 - i;
     */
    while (i < 5) {
        bool f = false;
        size_t j = 0;

        /*@
            loop invariant 0 <= j <= 5;
            loop invariant (\valid((s)+(0..4)));
            loop invariant \forall integer k; 0 <= k < 5 ==> (0 <= (s)[(k)] <= 123);
            loop invariant (\valid((a)+(0..4)));
            loop invariant \forall integer k; 0 <= k < 5 ==> (0 <= (a)[(k)] <= 123);
            loop invariant \forall integer k, l; 0 <= k < l < 5 ==> ((s)[(k)] != (s)[(l)]);
            loop assigns j, f;
            loop variant 5 - j;
         */
        while (j < 5) {
            //@ assert 0 <= i < 5 && 0 <= j < 5;
            if (a[i] == s[j]) {
                f = true;
                break;
            }
            j++;
        }
        if (f) {
            ans++;
        }
        i++;
    }
    //@ assert 0 <= ans <= 5;
    return ans;
}
