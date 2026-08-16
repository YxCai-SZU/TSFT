#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_range(integer n) = 0 < n <= 100; */
/*@ predicate valid_number(integer x) = 1 <= x <= 1000; */
/*@ predicate valid_array(integer n, uint32_t* arr, integer len) = 
      len == n && 
      \forall integer i; 0 <= i < len ==> valid_number(arr[i]); */

/*@ logic integer array_len(integer n) = n; */

/*@ lemma count_bounds: 
      \forall integer i, integer count; 
      0 <= i && 0 <= count <= i ==> 0 <= count; */

/*@ requires valid_range(n);
    requires valid_array(n, numbers, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
 */
int32_t func(uint32_t n, uint32_t numbers[]) {
    uint32_t min = 100000;
    uint32_t i = 0;
    int32_t count = 0;
    
    //@ assert n > 0 && n <= 100;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant i == 0 ==> min == 100000;
        loop invariant i > 0 ==> min <= 1000;
        loop invariant \forall integer j; 0 <= j < n ==> 1 <= numbers[j] <= 1000;
        loop assigns i, min, count;
        loop variant n - i;
     */
    while (i < n) {
        uint32_t v = numbers[i];
        
        if (min > v) {
            min = v;
            count = count + 1;
        }
        
        i = i + 1;
        
        //@ assert 0 <= count <= i;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
