#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 0);
    requires ((a) + (b) + (c) >= (k));
    ensures \result <= k;
    ensures \result >= -k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k) {
    int kflag = 0;
    int cnt = 0;
    int i = 0;
    
    //@ assert kflag == 0 && cnt == 0 && i == 0;
    
    /*@
        loop invariant 0 <= i <= a;
        loop invariant 0 <= kflag <= k;
        loop invariant 0 <= cnt <= kflag;
        loop invariant ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 0);
        loop invariant ((a) + (b) + (c) >= (k));
        loop assigns i, kflag, cnt;
        loop variant a - i;
    */
    while (i < a) {
        if (kflag == k) {
            break;
        }
        cnt += 1;
        kflag += 1;
        i += 1;
    }
    
    i = 0;
    //@ assert 0 <= kflag <= k;
    
    /*@
        loop invariant 0 <= i <= b;
        loop invariant 0 <= kflag <= k;
        loop invariant 0 <= cnt <= kflag;
        loop invariant ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 0);
        loop invariant ((a) + (b) + (c) >= (k));
        loop assigns i, kflag;
        loop variant b - i;
    */
    while (i < b) {
        if (kflag == k) {
            break;
        }
        kflag += 1;
        i += 1;
    }
    
    i = 0;
    //@ assert 0 <= kflag <= k;
    
    /*@
        loop invariant 0 <= i <= c;
        loop invariant 0 <= kflag <= k;
        loop invariant -kflag <= cnt <= kflag;
        loop invariant ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 0);
        loop invariant ((a) + (b) + (c) >= (k));
        loop assigns i, kflag, cnt;
        loop variant c - i;
    */
    while (i < c) {
        if (kflag == k) {
            break;
        }
        cnt -= 1;
        kflag += 1;
        i += 1;
    }
    
    //@ assert cnt <= k;
    //@ assert cnt >= -k;
    return cnt;
}
