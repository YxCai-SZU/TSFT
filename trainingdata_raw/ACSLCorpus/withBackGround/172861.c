#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 1 <= n <= 200000; */

/*@ predicate valid_array(int *arr, integer n) =
    \valid(arr + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= n; */

/*@ predicate count_invariant(integer index, integer count, integer n) =
    0 <= index <= n && 0 <= count <= index; */

/*@ lemma count_bounds:
    \forall integer index, count, n;
    count_invariant(index, count, n) ==> 0 <= count <= n; */

/*@
    requires valid_range(n);
    requires valid_array(numbers, n);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *numbers) {
    int count = 0;
    int index = 0;
    
    //@ ghost int old_count = count;
    //@ ghost int old_index = index;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant valid_range(n);
        loop invariant valid_array(numbers, n);
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        bool check = true;
        int inner_index = 0;
        
        /*@
            loop invariant 0 <= inner_index <= index;
            loop invariant check == true ==> 
                \forall integer j; 0 <= j < inner_index ==> 
                    numbers[index] != numbers[j];
            loop invariant valid_range(n);
            loop invariant valid_array(numbers, n);
            loop assigns inner_index, check;
            loop variant index - inner_index;
        */
        while (inner_index < index) {
            if (numbers[index] == numbers[inner_index]) {
                check = false;
                break;
            }
            inner_index++;
        }
        
        if (check) {
            count++;
        }
        index++;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
