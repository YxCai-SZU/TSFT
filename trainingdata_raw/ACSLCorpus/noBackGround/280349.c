#include <stdbool.h>
/*@
    requires (3 <= (n) && (n) <= 20);
    requires \valid(p+(0..n-1));
    requires (\forall integer j; 0 <= j < (n) ==> 1 <= (p)[j] && (p)[j] <= (n));
    requires (\forall integer j; 0 <= j < (n)-1 ==> (p)[j] != (p)[j+1]);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n-2;
*/
int func(int n, int *p) {
    int cnt = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant cnt >= 0;
        loop invariant cnt <= i-1;
        loop invariant i-1 <= n-2;
        loop assigns cnt, i;
        loop variant n-i-1;
    */
    while (i < n - 1) {
        int p_im1 = p[i-1];
        int pi = p[i];
        int p_ip1 = p[i+1];
        
        //@ assert p_im1 != pi && pi != p_ip1;
        
        if ((pi < p_im1 && pi < p_ip1) || (pi > p_im1 && pi > p_ip1)) {
            cnt += 1;
        }
        i += 1;
    }
    return cnt;
}
