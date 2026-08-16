#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t sum;
    int64_t result;
    int64_t count;
    int64_t temp_sum;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    sum = a + b + 1;
    result = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant result == count;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop invariant sum == a + b + 1;
        loop assigns temp_sum, result, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
        result += 1;
        count += 1;
    }

    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}

int main() {
    return 0;
}
