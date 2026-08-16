#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_index_range(integer n) = 1 <= n && n <= 200000; */
/*@ predicate valid_array(int64_t *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000000; */

/*@ lemma index_bound: \forall integer n; valid_index_range(n) ==> n >= 1; */

/*@ requires valid_index_range(n);
    requires \valid_read(input_numbers + (0 .. n-1));
    requires valid_array(input_numbers, n);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int32_t func(int64_t n, int64_t *input_numbers) {
    int64_t p = 1;
    int32_t count = 0;
    int64_t index = 0;
    
    /*@ loop invariant 0 <= index && index <= n;
        loop invariant 0 <= count && count <= index;
        loop invariant p >= 1;
        loop assigns p, count, index;
        loop variant n - index;
    */
    while (index < n) {
        int64_t a = input_numbers[index];
        
        //@ assert a >= 1 && a <= 1000000;
        
        if (a >= p) {
            //@ assert a >= p;
            count += 1;
            p = a;
        }
        
        //@ assert count <= (int32_t)index + 1;
        index += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= (int32_t)n;
    return count;
}
