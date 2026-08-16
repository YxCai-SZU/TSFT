#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *p, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ lemma cnt_bound: \forall integer cnt, i, n;
      cnt >= 0 && cnt <= i-1 && i <= n+1 ==> cnt <= n;
*/

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires valid_array(p, n);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int *p) {
    int cnt = 0;
    size_t index = 0;
    int i = 1;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 1 <= i <= n+1;
        loop invariant cnt >= 0;
        loop invariant cnt <= i-1;
        loop invariant valid_array(p, n);
        loop assigns cnt, index, i;
        loop variant n - index;
    */
    while (index < (size_t)n && i <= n) {
        int p_i = p[index];
        
        //@ assert 0 <= index < n ==> p_i >= 1 && p_i <= n;
        
        if (i <= p_i) {
            cnt = cnt + 1;
            i = i + 1;
        }
        index = index + 1;
    }
    
    //@ assert cnt <= n;
    return cnt;
}
