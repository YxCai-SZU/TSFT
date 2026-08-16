#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer num) = num % 2 == 0; */

/*@ predicate valid_number(integer x) = 1 <= x <= 1000; */

/*@ predicate valid_array(unsigned int* arr, integer n) =
      \forall integer i; 0 <= i < n ==> valid_number(arr[i]); */

/*@ lemma count_bound:
      \forall integer count, integer index;
      count >= 0 && count <= index ==> count <= index; */

/*@ requires n <= 100;
    requires \valid(numbers + (0 .. n-1));
    requires valid_array(numbers, n);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
unsigned int func(size_t n, const unsigned int* numbers) {
    unsigned int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant count >= 0;
        loop invariant count <= index;
        loop invariant valid_array((unsigned int*)numbers, n);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        unsigned int i = numbers[index];
        //@ assert valid_number(i);
        
        bool even = false;
        unsigned int n_temp = i;
        /*@ loop invariant 0 <= n_temp <= i;
            loop invariant n_temp % 2 == i % 2;
            loop assigns n_temp;
            loop variant n_temp;
        */
        while (n_temp >= 2) {
            n_temp -= 2;
        }
        even = (n_temp == 0);
        
        if (even) {
            count += 1;
        }
        //@ assert count <= index + 1;
        index += 1;
    }
    return count;
}
