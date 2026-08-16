#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int min_a_b;
    int max_a_b;
    int answer;

    if (a < b) {
        min_a_b = a;
    } else {
        min_a_b = b;
    }
    if (a > b) {
        max_a_b = a;
    } else {
        max_a_b = b;
    }

    answer = 0;

    if (max_a_b - min_a_b < 2) {
        answer = a + b;
    } else if (a == b) {
        answer = a + b;
    } else if (a == b - 1) {
        answer = a + b;
    } else if (b == a - 1) {
        answer = a + b;
    } else {
        answer = 2 * max_a_b - 1;
    }

    //@ assert answer == a + b || answer == 2 * a - 1 || answer == 2 * b - 1;
    return answer;
}
