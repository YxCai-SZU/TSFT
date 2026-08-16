#include <stdbool.h>

/*@
    predicate valid_numbers(int *numbers) =
        \valid(numbers) && numbers[0] >= 1 && numbers[0] <= 20 &&
        numbers[1] >= 1 && numbers[1] <= 20;

    logic integer sum_of_numbers(integer a, integer b) = a + b;

    lemma overflow_lemma:
        \forall integer a, b;
        a >= 1 && a <= 20 && b >= 1 && b <= 20 ==>
        a + b >= 2 && a + b <= 40;
*/

/*@
    requires valid_numbers(numbers);
    ensures
        (\result == 0 && numbers[0] + numbers[1] < 10) ||
        (\result == (numbers[0] + numbers[1] - 10) && numbers[0] + numbers[1] >= 10);
    assigns \nothing;
*/
int func(int *numbers)
{
    int sum;
    int result;
    bool is_overflow;

    sum = numbers[0] + numbers[1];
    result = 0;
    is_overflow = false;

    if (sum >= 10)
    {
        is_overflow = true;
    }

    if (is_overflow)
    {
        result = sum - 10;
        //@ assert result == (numbers[0] + numbers[1] - 10);
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }

    return result;
}
