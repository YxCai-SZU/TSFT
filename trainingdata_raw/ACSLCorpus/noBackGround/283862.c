#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 3 &&
        1 <= (input)[0] && (input)[0] <= 5000 &&
        1 <= (input)[1] && (input)[1] <= 5000 &&
        1 <= (input)[2] && (input)[2] <= 10000);
    ensures \result == (((input[0]) + (input[1]) >= (input[2]) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(const int *input, size_t len)
{
    int a;
    int b;
    int c;
    bool result;

    a = input[0];
    b = input[1];
    c = input[2];
    result = (a + b >= c);

    //@ assert result == (a + b >= c);
    return result;
}
