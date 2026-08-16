#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(integer N) = 1 <= N && N <= 100; */
/*@ predicate is_valid_array(integer N, long long *a, integer len) =
      len == N &&
      \forall integer i; 0 <= i < len ==> 1 <= a[i] && a[i] <= 100; */

/*@ requires is_valid_range(N);
    requires is_valid_array(N, a, N);
    requires \valid(a + (0 .. N-1));
    ensures 0 <= \result <= N;
    assigns \nothing;
*/
int func(long long N, const long long *a) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= N;
        loop invariant 0 <= count <= (int)index;
        loop invariant index <= N;
        loop assigns count, index;
        loop variant N - index;
    */
    while (index < (size_t)N) {
        long long value = a[index];
        
        //@ assert 0 <= index < N;
        //@ assert 1 <= value <= 100;
        
        if (((index + 1) & 1) != 0 && (value & 1) != 0) {
            //@ assert count >= 0;
            //@ assert count < (int)(index + 1);
            count += 1;
        }
        
        index += 1;
    }
    
    //@ assert index == N;
    //@ assert 0 <= count <= N;
    return count;
}
