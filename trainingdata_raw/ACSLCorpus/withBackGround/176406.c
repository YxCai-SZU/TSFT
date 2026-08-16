#include <stdbool.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 100; */
/*@ predicate is_valid_m(integer m) = 1 <= m && m <= 100; */
/*@ predicate is_valid_x(integer x, integer n) = 1 <= x && x <= n - 1; */
/*@ predicate valid_an_len(int *an, integer n) = \valid(an + (0..n-1)); */
/*@ predicate valid_bm_len(int *bm, integer m) = \valid(bm + (0..m-1)); */
/*@ predicate an_range(int *an, integer n) = 
      \forall integer k; 0 <= k < n ==> 1 <= an[k] && an[k] <= 100; */
/*@ predicate bm_range(int *bm, integer m) = 
      \forall integer k; 0 <= k < m ==> 1 <= bm[k] && bm[k] <= 100; */

/*@ logic integer max(integer a, integer b) = a > b ? a : b; */

/*@ lemma an_range_preserved: 
      \forall int *an, integer n, integer i; 
      an_range(an, n) && 0 <= i < n ==> 1 <= an[i] && an[i] <= 100; */

/*@ lemma bm_range_preserved: 
      \forall int *bm, integer m, integer i; 
      bm_range(bm, m) && 0 <= i < m ==> 1 <= bm[i] && bm[i] <= 100; */

/*@ requires is_valid_n(n);
    requires is_valid_m(m);
    requires is_valid_x(x, n);
    requires valid_an_len(an, n);
    requires an_range(an, n);
    requires valid_bm_len(bm, m);
    requires bm_range(bm, m);
    ensures \result >= 0;
*/
int func(int n, int m, int x, int *an, int *bm) {
    int ans_n;
    int i;
    int ans_m;
    int ans;

    ans_n = 0;
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans_n <= i;
        loop assigns i, ans_n;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (an[i] >= x) {
            ans_n = ans_n + 1;
        }
        i = i + 1;
    }

    ans_m = 0;
    i = 0;
    /*@ loop invariant 0 <= i <= m;
        loop invariant 0 <= ans_m <= i;
        loop assigns i, ans_m;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert i < m;
        if (bm[i] > x) {
            ans_m = ans_m + 1;
        }
        i = i + 1;
    }

    if (ans_n > ans_m) {
        ans = ans_n;
    } else {
        ans = ans_m;
    }

    //@ assert ans >= 0;
    return ans;
}
