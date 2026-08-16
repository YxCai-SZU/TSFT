#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool input_tuple(int a, int b) {
    bool result = false;
    int temp_a = a;
    int temp_b = b;
    int temp_sum = a + b;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((temp_a) >= 0 && (temp_a) <= (a) && (temp_a) % 3 == (a) % 3);

    /*@
        loop invariant ((temp_a) >= 0 && (temp_a) <= (a) && (temp_a) % 3 == (a) % 3);
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 3) {
        temp_a -= 3;
    }

    //@ assert ((temp_b) >= 0 && (temp_b) <= (b) && (temp_b) % 3 == (b) % 3);

    /*@
        loop invariant ((temp_b) >= 0 && (temp_b) <= (b) && (temp_b) % 3 == (b) % 3);
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 3) {
        temp_b -= 3;
    }

    //@ assert ((temp_sum) >= 0 && (temp_sum) <= (a) + (b) && (temp_sum) % 3 == ((a) + (b)) % 3);

    /*@
        loop invariant ((temp_sum) >= 0 && (temp_sum) <= (a) + (b) && (temp_sum) % 3 == ((a) + (b)) % 3);
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 3) {
        temp_sum -= 3;
    }

    //@ assert temp_a == a % 3;
    //@ assert temp_b == b % 3;
    //@ assert temp_sum == (a + b) % 3;

    if (temp_a == 0 || temp_b == 0 || temp_sum == 0) {
        result = true;
    }

    //@ assert result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    return result;
}
