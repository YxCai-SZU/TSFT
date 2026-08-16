#include <stdbool.h>
/*@
    requires ((1 <= ((n)) && ((n)) <= 100) && (1 <= ((m)) && ((m)) <= 100) && (0 <= ((x)) && ((x)) <= ((n)) - 1) &&
        (\valid(((an)) + (0..((n))-1))) && (\valid(((bn)) + (0..((m))-1))) &&
        (\forall integer i; 0 <= i < ((n)) ==> 0 <= ((an))[i] && ((an))[i] <= ((n)) - 1) && (\forall integer i; 0 <= i < ((m)) ==> 0 <= ((bn))[i] && ((bn))[i] <= ((n)) - 1) &&
        (\forall integer i, j; 0 <= i < j < ((n)) ==> ((an))[i] != ((an))[j]) && (\forall integer i, j; 0 <= i < j < ((m)) ==> ((bn))[i] != ((bn))[j]) &&
        (\forall integer i; 0 <= i < ((n)) ==> ((an))[i] != ((x))) && (\forall integer i; 0 <= i < ((m)) ==> ((bn))[i] != ((x))));
    ensures 0 <= \result && \result <= m;
    assigns \nothing;
*/
long func(long n, long m, long x, long *an, long *bn) {
    long ans = 0;
    long cnt = 0;
    long i = 0;
    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= cnt <= i;
        loop invariant 0 <= ans <= m;
        loop assigns i, cnt, ans;
        loop variant m - i;
    */
    while (i < m) {
        long v = bn[i];
        cnt = cnt + 1;
        //@ assert 0 <= cnt && cnt <= i + 1;
        if (v == x) {
            ans = cnt;
        }
        //@ assert 0 <= ans && ans <= m;
        i = i + 1;
    }
    //@ assert 0 <= ans && ans <= m;
    return ans;
}
