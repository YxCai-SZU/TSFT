#include <stddef.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result == (A + B) / 2 || \result == (A + B) / 2 + 1;
    ensures \result >= 1 && \result <= 100;
    assigns \nothing;
*/
size_t func(size_t A, size_t B)
{
    size_t sum;
    size_t avg;

    sum = A + B;
    avg = sum / 2;

    //@ assert sum >= 2 && sum <= 200;

    if (sum % 2 != 0)
    {
        avg = avg + 1;
        //@ assert avg == (A + B) / 2 + 1;
    }
    else
    {
        //@ assert avg == (A + B) / 2;
    }

    //@ assert avg >= 1 && avg <= 100;
    return avg;
}
