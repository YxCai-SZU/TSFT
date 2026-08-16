#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 100;
    requires 1 <= x <= 10000;
    requires \valid(distances + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (distances)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *distances) {
    int di = 0;
    int ans = 1;
    int i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n) &&
      1 <= (n) <= 100 &&
      1 <= (x) <= 10000 &&
      (di) >= 0 &&
      (di) <= (i) * 100 &&
      (ans) >= 1 &&
      (ans) <= (i) + 1 &&
      \forall integer j; 0 <= j < (i) ==> 1 <= (distances)[j] <= 100);
        loop assigns di, ans, i;
        loop variant n - i;
    */
    while (i < n) {
        int l = distances[i];
        di += l;
        
        //@ assert di >= 0;
        
        if (di > x) {
            break;
        }
        
        ans += 1;
        i += 1;
        
        //@ assert ans >= 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}
