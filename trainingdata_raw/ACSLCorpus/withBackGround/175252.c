#include <stddef.h>

/*@
    predicate valid_k(integer k) = 1 <= k <= 100;

    logic integer div2(integer count) = count / 2;
    logic integer div5(integer count) = count / 5;
    logic integer div20(integer count) = count / 20;

    logic integer expected_result(integer k) = 
        800 * k - 200 * div2(k) - 200 * div5(k) - 200 * div20(k);
*/

/*@
    requires valid_k(k);
    ensures \result == expected_result(k);
*/
int func(size_t k) {
    int num;
    size_t count;
    size_t two;
    size_t five;
    size_t twenty;
    size_t temp_count;

    num = 800 * (int)k;
    count = k;
    two = 0;
    five = 0;
    twenty = 0;

    // Manually implement division by 2
    temp_count = count;
    /*@
        loop invariant 0 <= temp_count <= count;
        loop invariant two <= div2(count);
        loop invariant temp_count == count - 2 * two;
        loop assigns temp_count, two;
    */
    while (temp_count >= 2) {
        //@ assert temp_count >= 2;
        temp_count -= 2;
        two += 1;
    }

    // Manually implement division by 5
    temp_count = count;
    /*@
        loop invariant 0 <= temp_count <= count;
        loop invariant five <= div5(count);
        loop invariant temp_count == count - 5 * five;
        loop assigns temp_count, five;
    */
    while (temp_count >= 5) {
        //@ assert temp_count >= 5;
        temp_count -= 5;
        five += 1;
    }

    // Manually implement division by 20
    temp_count = count;
    /*@
        loop invariant 0 <= temp_count <= count;
        loop invariant twenty <= div20(count);
        loop invariant temp_count == count - 20 * twenty;
        loop assigns temp_count, twenty;
    */
    while (temp_count >= 20) {
        //@ assert temp_count >= 20;
        temp_count -= 20;
        twenty += 1;
    }

    num = num - 200 * (int)two - 200 * (int)five - 200 * (int)twenty;

    //@ assert num == expected_result(k);
    return num;
}

int main() {
    return 0;
}
