#include <stdbool.h>

/*@ requires 1 <= r <= 100;
    ensures \result == 2 * r * 3;
    assigns \nothing;
 */
int func(int r)
{
    int pi = 3;
    int circumference;
    circumference = 2 * r * pi;
    //@ assert circumference == 2 * r * 3;
    return circumference;
}

/*@ requires 1 <= r <= 100;
    requires circumference == 2 * r * 3;
    ensures circumference == 2 * r * 3;
 */
void proof_func(int r, int circumference)
{
    //@ assert circumference == 2 * r * 3;
}
