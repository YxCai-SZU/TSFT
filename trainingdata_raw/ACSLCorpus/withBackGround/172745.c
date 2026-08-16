#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_numbers(integer n, int *numbers) =
    n > 0 && n <= 200 &&
    \valid(numbers + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 1000000000;
*/

/*@ logic integer min_value(integer a, integer b) =
    a < b ? a : b;
*/

/*@ lemma result_bounds:
    \forall integer n, int *numbers, integer result;
    valid_numbers(n, numbers) && 0 <= result <= 200 ==>
    \forall integer i; 0 <= i < n ==>
    min_value(result, (numbers[i] < 2020 ? 2020 - numbers[i] : 0)) >= 0 &&
    min_value(result, (numbers[i] < 2020 ? 2020 - numbers[i] : 0)) <= 200;
*/

/*@ requires valid_numbers(n, numbers);
    assigns \nothing;
    ensures \result >= 0 && \result <= 200;
*/
int func(size_t n, int *numbers) {
    int result = 200;
    size_t index = 0;
    int a, b;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant result >= 0 && result <= 200;
        loop invariant \forall integer j; 0 <= j < index ==> 
            result <= (numbers[j] < 2020 ? 2020 - numbers[j] : 0);
        loop assigns index, result, a, b;
        loop variant n - index;
    */
    while (index < n) {
        a = numbers[index];
        b = (a < 2020) ? (2020 - a) : 0;
        
        //@ assert b >= 0 && b <= 2020;
        
        result = (result < b) ? result : b;
        
        index++;
    }
    
    return result;
}
