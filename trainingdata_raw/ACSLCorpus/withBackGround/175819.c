#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer x, integer y) =
        3 <= n <= 2000 &&
        1 <= x <= n &&
        1 <= y <= n &&
        x + 1 < y;

    logic integer max_ans(integer n) = (n - 1) * (n - 2) / 2;

    lemma ans_bounds:
        \forall integer n; 3 <= n <= 2000 ==> 0 <= max_ans(n);
*/

/*@
    requires valid_params(n, x, y);
    ensures 0 <= \result <= max_ans(n);
    assigns \nothing;
*/
int func(int n, int x, int y) {
    int ans = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant 0 <= ans <= max_ans(n);
        loop assigns i, ans;
        loop variant n + 1 - i;
    */
    while (i < n + 1) {
        int j = 1;
        
        /*@
            loop invariant 1 <= j <= n + 1;
            loop invariant 0 <= ans <= max_ans(n);
            loop assigns j, ans;
            loop variant n + 1 - j;
        */
        while (j < n + 1) {
            int k = 1;
            
            /*@
                loop invariant 1 <= k <= n + 1;
                loop invariant 0 <= ans <= max_ans(n);
                loop assigns k, ans;
                loop variant n + 1 - k;
            */
            while (k < n + 1) {
                int cx = (i < x) ? i : (i - 1);
                int cy = (j < y) ? j : (j - 1);
                int ck = (k < y) ? k : (k - 1);
                
                //@ assert 0 <= cx <= n - 1 && 0 <= cy <= n - 1 && 0 <= ck <= n - 1;
                
                int condition = (i != j && j != k && k != i && 
                                (y - j) + (j - i) == x - i && 
                                (y - k) + (k - i) == x - i) ? 1 : 0;
                
                //@ assert 0 <= condition <= 1;
                
                ans += condition;
                
                //@ assert 0 <= ans <= max_ans(n) + 1;
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= ans <= max_ans(n);
    return ans;
}

int main() {
    return 0;
}
