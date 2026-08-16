#include <stdint.h>
#include <stdbool.h>

/*@ requires N > 0 && N <= 100000;
    requires N_Q > 0 && N_Q <= 100000;
    requires \valid(arr + (0 .. N-1));
    requires \valid(arr_s + (0 .. N_Q-1));
    assigns \nothing;
    ensures \result <= N_Q;
*/
uint32_t func(uint32_t N, uint32_t* arr, uint32_t N_Q, uint32_t* arr_s) {
    uint32_t ans = 0;
    uint32_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (N_Q) &&
      0 <= (ans) <= (i) &&
      (ans) <= (N_Q) &&
      (((N)) > 0 && ((N)) <= 100000 &&
      ((N_Q)) > 0 && ((N_Q)) <= 100000 &&
      \valid(((arr)) + (0 .. ((N))-1)) &&
      \valid(((arr_s)) + (0 .. ((N_Q))-1))));
        loop assigns i, ans;
        loop variant N_Q - i;
    */
    while (i < N_Q) {
        uint32_t t = arr_s[i];
        uint32_t j = 0;
        
        /*@ loop invariant (0 <= (j) <= (N) &&
      0 <= (i) < (N_Q) &&
      0 <= (ans) <= (i) &&
      (ans) <= (N_Q) &&
      (((N)) > 0 && ((N)) <= 100000 &&
      ((N_Q)) > 0 && ((N_Q)) <= 100000 &&
      \valid(((arr)) + (0 .. ((N))-1)) &&
      \valid(((arr_s)) + (0 .. ((N_Q))-1))));
            loop assigns j, ans;
            loop variant N - j;
        */
        while (j < N) {
            if (arr[j] == t) {
                ans += 1;
                break;
            }
            j += 1;
        }
        i += 1;
        //@ assert i > 0;
    }
    return ans;
}
