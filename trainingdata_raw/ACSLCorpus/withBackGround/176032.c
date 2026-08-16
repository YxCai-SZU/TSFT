#include <stdbool.h>

/*@
    predicate valid_numbers(long *numbers) =
        \valid(numbers) &&
        numbers[0] >= 1 && numbers[0] <= 20 &&
        numbers[1] >= 1 && numbers[1] <= 20 &&
        numbers[2] >= 1 && numbers[2] <= 20;

    logic integer func_result(integer a, integer b, integer c) =
        a + b < c ? a + b : c;
*/

/*@
    requires valid_numbers(numbers);
    ensures \result >= 0 && \result <= numbers[2];
    ensures \result == func_result(numbers[0], numbers[1], numbers[2]);
*/
long func(long *numbers)
{
    long result;
    long temp;
    result = 0;
    temp = numbers[0] + numbers[1];
    //@ assert temp == numbers[0] + numbers[1];
    if (temp < numbers[2])
    {
        result = temp;
        //@ assert result == numbers[0] + numbers[1];
    }
    else
    {
        result = numbers[2];
        //@ assert result == numbers[2];
    }
    //@ assert result >= 0;
    return result;
}

/*@
    predicate valid_x(integer x) = 1 <= x && x <= 100;

    logic integer quotient_value(integer x) = x / 15;

    logic integer func2_result(integer x) = x * 800 - (x / 15) * 200;

    lemma quotient_bound: \forall integer x; valid_x(x) ==> 0 <= quotient_value(x) && quotient_value(x) <= 6;
*/

/*@
    requires 1 <= x && x <= 100;
    ensures \result == x * 800 - (x / 15) * 200;
    ensures \result == func2_result(x);
*/
long func2(long x)
{
    long quotient;
    long temp_x;
    quotient = 0;
    temp_x = x;
    //@ assert temp_x == x && quotient == 0;
    /*@
        loop invariant 0 <= quotient <= x / 15;
        loop invariant temp_x == x - quotient * 15;
        loop invariant temp_x >= 0;
        loop assigns quotient, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 15)
    {
        //@ assert temp_x >= 15;
        quotient = quotient + 1;
        temp_x = temp_x - 15;
        //@ assert temp_x == x - quotient * 15;
    }
    //@ assert quotient == x / 15;
    //@ assert temp_x == x % 15;
    return x * 800 - quotient * 200;
}
