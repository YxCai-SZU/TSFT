#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(input + (0 .. 1));
    requires ((len) == 2 &&
        1 <= (input)[0] && (input)[0] <= 20 &&
        1 <= (input)[1] && (input)[1] <= 20);
    assigns \nothing;
    ensures (((\result) == (((input[0])) + ((input[1]))) && (\result) < 20) || (\result) == 0);
*/
long func(const long *input, size_t len)
{
    long result;
    long sum;

    //@ assert len == 2;
    //@ assert 1 <= input[0] && input[0] <= 20;
    //@ assert 1 <= input[1] && input[1] <= 20;

    sum = input[0] + input[1];
    //@ assert sum == ((input[0]) + (input[1]));

    if (sum < 20)
    {
        result = sum;
        //@ assert result == ((input[0]) + (input[1])) && result < 20;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }

    //@ assert (((result) == (((input[0])) + ((input[1]))) && (result) < 20) || (result) == 0);
    return result;
}
