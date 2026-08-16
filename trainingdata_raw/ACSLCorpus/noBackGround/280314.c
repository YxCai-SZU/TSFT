#include <stdint.h>
#include <stddef.h>

/*@
    requires (2 <= (N) <= 200000);
    requires ((len) == (size_t)((N) - 1));
    requires \valid_read(input_vec + (0 .. len-1));
    requires (\forall size_t j; 0 <= j < ((len)) ==> 
            (input_vec)[j] >= 1 && (input_vec)[j] < (int64_t)j + 2);
    ensures \result >= 0;
    ensures \result <= N;
*/
int64_t func(int64_t N, const int64_t *input_vec, size_t len) {
    int64_t ans = 0;
    int64_t i = 1;
    size_t index = 0;
    
    /*@
        loop invariant (0 <= (index) <= (len));
        loop invariant (1 <= (i) <= (int64_t)(index) + 1);
        loop invariant (0 <= (ans) <= (int64_t)(index));
        loop invariant (\forall size_t j; 0 <= j < (index) ==> 
            (input_vec)[j] >= 1 && (input_vec)[j] < (int64_t)j + 2);
        loop assigns ans, i, index;
        loop variant len - index;
    */
    while (index < len) {
        int64_t a = input_vec[index];
        if (i == a) {
            ans += 1;
            i += 1;
        }
        index += 1;
    }
    return ans;
}
