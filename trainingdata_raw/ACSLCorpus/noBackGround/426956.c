#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures ((\result) == (((a)) * 2) || (\result) == (((b)) * 2) ||
        (\result) == (((a)) * 2 - 1) || (\result) == (((b)) * 2 - 1));
*/
int func(int a, int b)
{
    int local_a = a;
    int local_b = b;
    bool is_a_max = false;

    //@ assert (3 <= (local_a) && (local_a) <= 20) && (3 <= (local_b) && (local_b) <= 20);

    if (local_a > local_b) {
        is_a_max = true;
    } else {
        int temp = local_a;
        local_a = local_b;
        local_b = temp;
    }

    //@ assert local_a >= local_b;

    int max_val;
    if (is_a_max) {
        max_val = local_a;
    } else {
        max_val = local_b;
    }

    //@ assert max_val == local_a || max_val == local_b;

    if (max_val == local_a) {
        int result = local_a * 2 - 1;
        //@ assert result == ((local_a) * 2 - 1);
        return result;
    } else {
        int result = local_b * 2 - 1;
        //@ assert result == ((local_b) * 2 - 1);
        return result;
    }
}
