#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_array(int32_t* arr, integer n) =
        n >= 3 && n <= 200000 &&
        n % 2 == 1 &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000000000;

    logic integer count_bound(integer index, integer n) =
        index - 1;
*/

/*@
    requires valid_array(numbers, n);
    ensures 0 <= \result <= n/2;
    assigns \nothing;
*/
int32_t func(uint32_t n, int32_t* numbers) {
    int32_t count = 0;
    uint32_t index = 1;
    
    //@ ghost uint32_t old_n = n;
    
    /*@
        loop invariant 1 <= index <= n/2 + 1;
        loop invariant 0 <= count <= count_bound(index, old_n);
        loop invariant valid_array(numbers, old_n);
        loop invariant n == old_n;
        loop assigns count, index;
        loop variant n/2 + 1 - index;
    */
    while (index < (n / 2) + 1) {
        int32_t num = numbers[index];
        int32_t num2 = numbers[n - index];
        
        //@ assert index > 0 && n - index < old_n;
        
        if ((num & 1) == 1 && (num2 & 1) == 1) {
            count += 1;
        }
        
        index += 1;
    }
    
    //@ assert count <= n/2;
    return count;
}
