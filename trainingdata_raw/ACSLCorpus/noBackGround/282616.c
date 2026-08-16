#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;
    //@ ghost int64_t original_c = c;

    result = c - (a - b);

    if (result > 0)
    {
        //@ assert result >= 0;
        return result;
    }
    else
    {
        return 0;
    }
}
