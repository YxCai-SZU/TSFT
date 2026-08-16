#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer num) = (num & 1) == 0; */

/*@ predicate valid_params(integer n, int *numbers) =
    n >= 1 && n <= 1000000 &&
    \valid(numbers + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 1000000000;
*/

/*@ predicate loop_invariant(integer n, int *numbers, integer index, integer count) =
    0 <= index <= n &&
    0 <= count <= index &&
    valid_params(n, numbers);
*/


int func(int n, int *numbers) {
    int count = 0;
    size_t index = 0;
    
    
    while (index < (size_t)n) {
        int a = numbers[index];
        //@ assert a >= 1 && a <= 1000000000;
        
        if ((a & 1) == 0) {
            count += 1;
        }
        index += 1;
    }
    
    if (count == n) {
        return -1;
    } else {
        return count;
    }
}
