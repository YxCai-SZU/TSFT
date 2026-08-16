#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_valid_array(unsigned long *arr, integer n) =
        n >= 2 && n <= 200000 &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000000000;

    predicate satisfies_condition(unsigned long *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 
            (arr[i] % 2 == 0 ==> (arr[i] % 3 == 0 || arr[i] % 5 == 0));

    lemma array_bounds_preserved:
        \forall unsigned long *arr, integer n, integer i;
            is_valid_array(arr, n) && 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000000000;
*/

/*@
    requires \valid_read(input + (0 .. n-1));
    requires is_valid_array(input, n);
    assigns \nothing;
    ensures \result == true <==> satisfies_condition(input, n);
*/
bool func(size_t n, const unsigned long *input) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant is_valid_array(input, n);
        loop invariant \forall integer j; 0 <= j < i ==> 
            (input[j] % 2 == 0 ==> (input[j] % 3 == 0 || input[j] % 5 == 0));
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        unsigned long value = input[i];
        
        //@ assert 1 <= value && value <= 1000000000;
        
        if (value % 2 == 0 && (value % 3 != 0 && value % 5 != 0)) {
            //@ assert !satisfies_condition(input, n);
            return false;
        }
        
        i++;
    }
    
    //@ assert satisfies_condition(input, n);
    return true;
}
