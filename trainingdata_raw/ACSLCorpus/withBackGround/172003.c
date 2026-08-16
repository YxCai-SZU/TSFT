#include <stdbool.h>

/*@ predicate valid_number(integer v) = 1 <= v <= 1000000; */

/*@ predicate valid_index_range(integer i, integer n) = 0 <= i < n; */

/*@ predicate array_valid_range(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> valid_number(arr[i]); */

/*@ lemma count_bounds: 
      \forall integer i, integer count; 0 <= i && 0 <= count <= i ==> count >= 0; */

/*@ requires 1 <= n <= 200000;
    requires \valid(numbers + (0 .. n-1));
    requires array_valid_range(numbers, n);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
 */
int func(int n, int *numbers) {
    int count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant array_valid_range(numbers, n);
        loop invariant 1 <= n <= 200000;
        loop assigns count, i;
        loop variant n - i;
     */
    while (i < n) {
        int a = numbers[i];
        bool is_even = (a & 1) == 0;
        
        //@ assert valid_number(a);
        
        if (is_even) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    
    return count;
}
