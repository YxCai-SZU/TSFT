#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_array(int32_t *arr, integer len) =
        len >= 1 && len <= 100000 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 1000000000;

    logic integer max(integer a, integer b) = a > b ? a : b;

    lemma cnt_bound: \forall integer index, integer cnt; 0 <= cnt <= index ==> cnt <= index;
*/

/*@
    requires N >= 1 && N <= 100000;
    requires \valid(Hs + (0 .. N-1));
    requires valid_array(Hs, N);
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
int32_t func(int32_t N, int32_t *Hs) {
    int32_t ans = 0;
    int32_t acc = 0;
    int32_t cnt = 0;
    int32_t index = 0;
    
    /*@
        loop invariant 0 <= index <= N;
        loop invariant 0 <= cnt <= index;
        loop invariant 0 <= ans <= index;
        loop invariant acc >= 0;
        loop invariant valid_array(Hs, N);
        loop assigns ans, acc, cnt, index;
    */
    while (index < N) {
        int32_t H = Hs[index];
        
        if (acc <= H) {
            acc = H;
            cnt = cnt + 1;
        }
        
        //@ assert cnt <= index + 1;
        
        if (ans < cnt) {
            ans = cnt;
        }
        
        //@ assert ans <= index + 1;
        index = index + 1;
    }
    
    //@ assert ans <= N;
    return ans;
}
