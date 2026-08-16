#include <stdbool.h>
#include <stddef.h>

/*@
requires (1 <= (n) && (n) <= 100);
requires (\valid((input_numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> 0 <= (input_numbers)[i] && (input_numbers)[i] <= 100);
ensures \result >= 0;
*/
long func(long n, long *input_numbers)
{
    long max_value = input_numbers[0];
    long min_value = input_numbers[0];
    long i = 1;
    
    //@ assert max_value >= 0;
    //@ assert max_value <= 100;
    //@ assert min_value >= 0;
    //@ assert min_value <= 100;
    //@ assert max_value >= min_value;
    
    /*@ loop invariant 1 <= i && i <= n;
        loop invariant max_value >= min_value;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max_value) >= (input_numbers)[k]);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (min_value) <= (input_numbers)[k]);
        loop invariant \forall integer k; 0 <= k < n ==> 0 <= input_numbers[k] && input_numbers[k] <= 100;
        loop assigns max_value, min_value, i;
        loop variant n - i;
    */
    while (i < n) {
        long number = input_numbers[i];
        
        //@ assert 0 <= number && number <= 100;
        
        if (number > max_value) {
            max_value = number;
        }
        
        if (number < min_value) {
            min_value = number;
        }
        
        i = i + 1;
    }
    
    //@ assert max_value >= min_value;
    return max_value - min_value;
}
