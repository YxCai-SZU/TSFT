#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100 &&
        1 <= (x) && (x) <= (n) - 1 &&
        \valid((an) + (0 .. (m)-1)) &&
        \forall integer i; 0 <= i < (m) ==> 
            (an)[i] >= 1 && (an)[i] <= (n) && (an)[i] != (x));
    ensures 0 <= \result <= m;
    assigns \nothing;
*/
int func(int n, int m, int x, int *an) {
    int ans_n = 0;
    int ans_0 = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (m) &&
        (ans_n) >= 0 && (ans_0) >= 0 &&
        (ans_n) + (ans_0) <= (i) &&
        \forall integer j; 0 <= j < (i) ==> 
            (an)[j] >= 1 && (an)[j] <= (n) && (an)[j] != (x));
        loop assigns i, ans_n, ans_0;
        loop variant m - i;
    */
    while (i < m) {
        int a = an[i];
        //@ assert a >= 1 && a <= n && a != x;
        
        if (a > x && a < n) {
            ans_n++;
        }
        if (a < x && a > 0) {
            ans_0++;
        }
        i++;
        
        //@ assert ans_n + ans_0 <= i;
    }
    
    int ans = (ans_n < ans_0) ? ans_n : ans_0;
    //@ assert 0 <= ans <= m;
    return ans;
}
