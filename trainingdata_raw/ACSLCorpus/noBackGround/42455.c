#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 1000 &&
        1 <= (B) && (B) <= 1000 &&
        (A) + (B) <= (X) && (X) <= 10000);
    ensures \result >= 0 && \result <= X;
    ensures \result == X - A || \result == X - B || \result == X - A - B;
*/
int64_t func(int64_t X, int64_t A, int64_t B)
{
    int64_t max_val;
    int64_t min_ops;
    int64_t result;

    //@ assert (1 <= (A) && (A) <= 1000 &&         1 <= (B) && (B) <= 1000 &&         (A) + (B) <= (X) && (X) <= 10000);

    // Find the maximum value between A and B
    if (A > B) {
        max_val = A;
    } else {
        max_val = B;
    }

    // Calculate the minimum number of operations required
    if (X > max_val) {
        min_ops = 1;
    } else {
        min_ops = 2;
    }

    // Calculate the result
    if (X > max_val) {
        result = X - max_val;
    } else {
        result = 0;
    }

    //@ assert result == X - A || result == X - B || result == X - A - B;

    return result;
}
