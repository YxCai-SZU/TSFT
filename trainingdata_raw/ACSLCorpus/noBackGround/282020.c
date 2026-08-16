#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 3 &&
        1 <= (B) && (B) <= 3 &&
        (A) != (B));
    ensures \result == (6 - ((A) + (B)));
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;

    //@ assert (1 <= (A) && (A) <= 3 &&         1 <= (B) && (B) <= 3 &&         (A) != (B));
    //@ assert (6 - ((A) + (B))) == 6 - (A + B);

    result = 6 - (A + B);

    //@ assert result == (6 - ((A) + (B)));
    return result;
}
