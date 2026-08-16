#include <limits.h>

/*@ requires (1 <= (n) && (n) <= 20 &&
      1 <= (a) && (a) <= 50 &&
      1 <= (b) && (b) <= 50);
    ensures \result >= 0;
    ensures \result <= b;
    ensures \result <= n * a;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int train;
    int taxi;
    int min_val;

    //@ assert (1 <= (n) && (n) <= 20 &&       1 <= (a) && (a) <= 50 &&       1 <= (b) && (b) <= 50);
    //@ assert n * a <= 1000;

    train = a * n;
    taxi = b;

    if (train < taxi) {
        min_val = train;
    } else {
        min_val = taxi;
    }

    //@ assert min_val >= 0;
    //@ assert min_val <= b;
    //@ assert min_val <= n * a;

    return min_val;
}
