#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_array(integer n, uint64_t *arr) =
        n >= 1 && n <= 100000 &&
        \valid(arr + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> arr[j] >= 1 && arr[j] <= 1000000000;

    predicate outer_loop_inv(integer n, uint64_t *arr, integer i, uint64_t count) =
        0 <= i <= n &&
        count <= i &&
        valid_array(n, arr);

    predicate inner_loop2_inv(integer n, uint64_t *arr, integer i, uint64_t n2) =
        1 <= n2 <= 100 &&
        0 <= i < n &&
        valid_array(n, arr);

    predicate inner_loop3_inv(integer n, uint64_t *arr, integer i, uint64_t n2, uint64_t n3) =
        1 <= n3 <= 100 &&
        1 <= n2 <= 100 &&
        0 <= i < n &&
        valid_array(n, arr);
*/

/*@
    requires valid_array(n, numbers);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t *numbers) {
    uint64_t count = 0;
    uint64_t i = 0;
    
    /*@
        loop invariant outer_loop_inv(n, numbers, i, count);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        uint64_t a = numbers[i];
        bool is_divisible = false;
        uint64_t n2 = 1;
        
        /*@
            loop invariant inner_loop2_inv(n, numbers, i, n2);
            loop assigns n2, is_divisible;
            loop variant 100 - n2;
        */
        while (n2 < 100) {
            uint64_t n3 = 1;
            
            /*@
                loop invariant inner_loop3_inv(n, numbers, i, n2, n3);
                loop assigns n3, is_divisible;
                loop variant 100 - n3;
            */
            while (n3 < 100) {
                uint64_t sum = n2 + n3;
                if (sum > a) break;
                if (a % sum == 0) {
                    is_divisible = true;
                    break;
                }
                n3++;
            }
            if (is_divisible) break;
            n2++;
        }
        if (is_divisible) count++;
        i++;
    }
    return count;
}
