#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int* arr, size_t n) =
        n > 0 && n <= 100000 &&
        \valid(arr + (0 .. n-1)) &&
        \forall size_t i; 0 <= i < n ==> 1 <= arr[i] <= 1000000000;
*/

/*@
    requires valid_array(hs, n);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t n, int* hs) {
    int cur_h;
    int cur_n;
    size_t i;
    
    //@ assert n > 0 && n <= 100000;
    
    cur_h = hs[0];
    cur_n = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant 0 <= cur_n <= i - 1;
        loop invariant 1 <= cur_h <= 1000000000;
        loop assigns i, cur_h, cur_n;
        loop variant n - i;
    */
    while (i < n) {
        int h = hs[i];
        
        //@ assert 1 <= h <= 1000000000;
        
        if (cur_h <= h) {
            cur_n = cur_n + 1;
        } else {
            cur_n = 0;
            cur_h = h;
        }
        
        i = i + 1;
    }
    
    return cur_n;
}

#ifdef TESTING
#include <assert.h>

int main() {
    int test_array[] = {3, 3, 5, 1, 4, 4};
    size_t n = 6;
    
    int result = func(n, test_array);
    assert(result == 2);
    
    return 0;
}
#endif
