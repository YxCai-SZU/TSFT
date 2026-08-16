#include <limits.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100);
    ensures \result == (((A + B) + 1) / 2);
    assigns \nothing;
*/
int func(int A, int B) {
    int sum;
    int result;
    int count;
    int temp_sum;

    sum = A + B;
    result = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
        count += 1;
    }

    //@ assert temp_sum == 0 || temp_sum == 1;

    if (temp_sum > 0 && sum > 0) {
        count += 1;
    }

    result = count;

    //@ assert result == (((A + B) + 1) / 2);
    return result;
}
