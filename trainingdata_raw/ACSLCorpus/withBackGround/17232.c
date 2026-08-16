#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_valid_range(long *input, integer len) =
        len == 5 &&
        \valid_read(input + (0 .. 4)) &&
        -100 <= input[0] <= 100 &&
        -100 <= input[1] <= 100 &&
        -100 <= input[2] <= 100 &&
        -100 <= input[3] <= 100 &&
        -100 <= input[4] <= 100;

    predicate is_result_valid(long result, long *input) =
        result >= -100 && result <= 100 &&
        (result == input[0] || result == input[1] || result == input[2] || 
         result == input[3] || result == input[4]);

    predicate loop_invariant(long *input, long tmp, integer i) =
        0 <= i <= 5 &&
        \valid_read(input + (0 .. 4)) &&
        tmp >= -100 && tmp <= 100 &&
        (tmp == input[0] || tmp == input[1] || tmp == input[2] || 
         tmp == input[3] || tmp == input[4]) &&
        (\forall integer k; 0 <= k < i ==> tmp >= input[k]);
*/

/*@
    requires is_valid_range(input, 5);
    ensures is_result_valid(\result, input);
    assigns \nothing;
*/
long func(const long *input) {
    long tmp;
    size_t i;

    tmp = input[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \valid_read(input + (0 .. 4));
        loop invariant tmp >= -100 && tmp <= 100;
        loop invariant tmp == input[0] || tmp == input[1] || tmp == input[2] || 
                      tmp == input[3] || tmp == input[4];
        loop invariant \forall integer k; 0 <= k < i ==> tmp >= input[k];
        loop assigns tmp, i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (input[i] > tmp) {
            tmp = input[i];
        }
        i++;
    }

    //@ assert is_result_valid(tmp, input);
    return tmp;
}
