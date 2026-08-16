#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        \valid((input) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (input)[i] >= 1 && (input)[i] <= 1000000000);
    ensures \result >= -1;
    ensures \result <= (int32_t)n - 1;
    assigns \nothing;
*/
int32_t func(size_t n, const int64_t *input)
{
    // Variable declarations
    int64_t before;
    int32_t answer;
    size_t index;

    before = input[0];
    answer = 0;
    index = 1;

    /*@
        loop invariant ((((n)) >= 1 && ((n)) <= 100000 &&
        \valid(((input)) + (0 .. ((n))-1)) &&
        \forall size_t i; 0 <= i < ((n)) ==> ((input))[i] >= 1 && ((input))[i] <= 1000000000) &&
        1 <= (index) && (index) <= (n) &&
        (answer) >= 0 &&
        (answer) <= (int32_t)(index) - 1);
        loop invariant index > 1 ==> \forall size_t j; 0 <= j < index ==> input[j] >= 1 && input[j] <= 1000000000;
        loop assigns before, answer, index;
        loop variant n - index;
    */
    while (index < n)
    {
        int64_t current = input[index];
        //@ assert current >= 1 && current <= 1000000000;
        
        if (before >= current)
        {
            answer = answer + 1;
        }
        else
        {
            before = current;
        }
        index = index + 1;
    }

    if (answer == 0)
    {
        return -1;
    }
    else
    {
        return answer;
    }
}
