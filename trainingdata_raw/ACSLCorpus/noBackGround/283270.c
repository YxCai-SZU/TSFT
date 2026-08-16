#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        1 <= (x) <= (n) - 1 &&
        (m) == (m) &&
        \valid((a_vec) + (0 .. (m)-1)) &&
        \forall integer i; 0 <= i < (m) ==> 1 <= (a_vec)[i] <= (n) &&
        \forall integer i; 0 <= i < (m) ==> (a_vec)[i] != (x));
    ensures 0 <= \result <= m;
    assigns \nothing;
*/
int func(int n, int m, int x, int *a_vec) {
    int ans;
    int cnt1;
    int cnt2;
    int i;
    int a;
    
    ans = 0;
    cnt1 = 0;
    cnt2 = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= cnt1 <= i;
        loop invariant 0 <= cnt2 <= i;
        loop invariant cnt1 + cnt2 == i;
        loop invariant \forall integer j; 0 <= j < i ==> a_vec[j] != x;
        loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        1 <= (x) <= (n) - 1 &&
        (m) == (m) &&
        \valid((a_vec) + (0 .. (m)-1)) &&
        \forall integer i; 0 <= i < (m) ==> 1 <= (a_vec)[i] <= (n) &&
        \forall integer i; 0 <= i < (m) ==> (a_vec)[i] != (x));
        loop assigns i, cnt1, cnt2, ans, a;
        loop variant m - i;
    */
    while (i < m) {
        a = a_vec[i];
        //@ assert a != x;
        if (a < x) {
            cnt1 = cnt1 + 1;
        } else {
            cnt2 = cnt2 + 1;
        }
        i = i + 1;
    }
    
    if (cnt1 < cnt2) {
        ans = cnt1;
    } else {
        ans = cnt2;
    }
    
    //@ assert 0 <= ans <= m;
    return ans;
}
