#include <stdint.h>
#include <limits.h>

/*@
    requires \valid(numbers + (0 .. 2));
    requires ((3) == 3 &&
        1 <= (numbers)[0] && (numbers)[0] <= 20 &&
        1 <= (numbers)[1] && (numbers)[1] <= 20 &&
        1 <= (numbers)[2] && (numbers)[2] <= 20);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= 2;
*/
int32_t func(int64_t* numbers)
{
    int32_t result = -1;
    int64_t i = 1;

    /*@
        loop invariant 1 <= i <= 20;
        loop invariant ((3) == 3 &&
        1 <= (numbers)[0] && (numbers)[0] <= 20 &&
        1 <= (numbers)[1] && (numbers)[1] <= 20 &&
        1 <= (numbers)[2] && (numbers)[2] <= 20);
        loop invariant ((result) == -1 || (result) == 0 || (result) == 1 || (result) == 2);
        loop assigns i, result;
        loop variant 20 - i;
    */
    while (i < 20)
    {
        int64_t sum = 0;
        int64_t j = 0;

        /*@
            loop invariant 0 <= j <= 3;
            loop invariant sum >= 0;
            loop invariant sum <= j * 20;
            loop invariant ((3) == 3 &&
        1 <= (numbers)[0] && (numbers)[0] <= 20 &&
        1 <= (numbers)[1] && (numbers)[1] <= 20 &&
        1 <= (numbers)[2] && (numbers)[2] <= 20);
            loop invariant ((result) == -1 || (result) == 0 || (result) == 1 || (result) == 2);
            loop assigns j, sum;
            loop variant 3 - j;
        */
        while (j < 3)
        {
            int64_t k = numbers[(int)j];
            int64_t diff = i - k;
            //@ assert diff >= -19 && diff <= 19;
            sum += (diff < 0) ? -diff : diff;
            //@ assert sum >= 0;
            j++;
        }

        if (sum < i)
        {
            result = 0;
            break;
        }
        i++;
    }

    if (result == -1)
    {
        result = 1;
    }

    //@ assert result >= 0 && result <= 2;
    return result;
}
