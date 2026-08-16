#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \valid((input_numbers) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 0 <= (input_numbers)[i] && (input_numbers)[i] <= 1000);
    ensures \result >= 0 && \result <= 1000;
    ensures \exists size_t y; 0 <= y < n && \result == input_numbers[y];
    ensures \forall size_t i; 0 <= i < n ==> \result >= input_numbers[i];
    assigns \nothing;
*/
int func(size_t n, int *input_numbers)
{
    int max_value;
    size_t i;

    //@ assert ((n) > 0 && (n) <= 100 &&         \valid((input_numbers) + (0 .. (n)-1)) &&         \forall size_t i; 0 <= i < (n) ==> 0 <= (input_numbers)[i] && (input_numbers)[i] <= 1000);
    max_value = input_numbers[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant ((n) > 0 && (n) <= 100 &&
        \valid((input_numbers) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 0 <= (input_numbers)[i] && (input_numbers)[i] <= 1000);
        loop invariant (\exists size_t y; 0 <= y < (i) && (max_value) == (input_numbers)[y]);
        loop invariant (\forall size_t k; 0 <= k < (i) ==> (max_value) >= (input_numbers)[k]);
        loop assigns max_value, i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert (\exists size_t y; 0 <= y < (i) && (max_value) == (input_numbers)[y]);
        if (input_numbers[i] > max_value)
        {
            max_value = input_numbers[i];
        }
        i = i + 1;
    }

    //@ assert (\exists size_t y; 0 <= y < (n) && (max_value) == (input_numbers)[y]);
    //@ assert \forall size_t i; 0 <= i < n ==> max_value >= input_numbers[i];
    return max_value;
}
