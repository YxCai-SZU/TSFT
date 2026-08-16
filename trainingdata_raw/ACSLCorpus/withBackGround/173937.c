#include <stdbool.h>
/*@
    predicate is_valid_range(integer n) =
        3 <= n && n <= 20;
    
    predicate is_valid_array(int *p, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= n;
    
    predicate is_distinct_array(int *p, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
    
    logic integer count_local_extrema(int *p, integer i) =
        (i <= 1) ? 0 :
        ((p[i-1] < p[i-2] && p[i-1] < p[i]) || (p[i-1] > p[i-2] && p[i-1] > p[i])) ?
        count_local_extrema(p, i-1) + 1 : count_local_extrema(p, i-1);
*/

/*@
    requires is_valid_range(n);
    requires \valid(p + (0 .. n-1));
    requires is_valid_array(p, n);
    requires is_distinct_array(p, n);
    ensures 0 <= \result <= n-2;
    assigns \nothing;
*/
int func(int n, int *p) {
    int cnt = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant 0 <= cnt <= i-1;
        loop invariant cnt == count_local_extrema(p, i);
        loop assigns cnt, i;
        loop variant n-1 - i;
    */
    while (i < n - 1) {
        int pi = p[i];
        int pi_1 = p[i - 1];
        int pi1 = p[i + 1];
        
        //@ assert pi_1 != pi && pi != pi1 && pi_1 != pi1;
        
        if ((pi < pi_1 && pi < pi1) || (pi > pi_1 && pi > pi1)) {
            cnt = cnt + 1;
        }
        
        i = i + 1;
    }
    
    return cnt;
}
