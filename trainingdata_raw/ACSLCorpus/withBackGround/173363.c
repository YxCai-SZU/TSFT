#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_range(integer N) = 1 <= N <= 100; */
/*@ predicate valid_array(integer N, int64_t *a, integer len) = 
      len == N && 
      \forall integer i; 0 <= i < len ==> 1 <= a[i] <= 100; */

/*@ requires valid_range(N);
    requires valid_array(N, a, N);
    ensures 0 <= \result <= N;
    assigns \nothing;
 */
int32_t func(int64_t N, int64_t *a) {
    int32_t count = 0;
    int64_t num = 0;
    size_t index = 0;
    size_t len = (size_t)N;
    
    /*@ loop invariant 0 <= index <= len;
        loop invariant 0 <= count <= index;
        loop invariant 0 <= num <= index * 100;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= a[i] <= 100;
        loop assigns count, num, index;
        loop variant len - index;
     */
    while (index < len) {
        int64_t value = a[index];
        num += value;
        
        //@ assert num >= 0;
        
        if (num >= N) {
            count += 1;
            num = 0;
        }
        
        //@ assert 0 <= count <= index + 1;
        
        index += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
