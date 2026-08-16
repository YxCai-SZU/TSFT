#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
      \valid((v) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (v)[i] >= 0 && (v)[i] <= 100);
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *v) {
    int ans = 0;
    int w = 0;
    int index = 0;
    
    /*@ loop invariant (0 <= (index) <= (n) &&
      0 <= (w) <= 101 &&
      0 <= (ans) <= (index) &&
      ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (v)[i] >= 0 && (v)[i] <= 100) &&
      (((n)) >= 1 && ((n)) <= 100 &&
      \valid(((v)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((v))[i] >= 0 && ((v))[i] <= 100));
        loop assigns ans, w, index;
        loop variant n - index;
    */
    while (w <= 100 && index < n) {
        int x = v[index];
        
        //@ assert x >= 0 && x <= 100;
        
        if (x <= w + 1) {
            ans += 1;
            w = 0;
        } else {
            w += 1;
        }
        index += 1;
        
        //@ assert ans <= index;
    }
    
    //@ assert ans <= n;
    return ans;
}
