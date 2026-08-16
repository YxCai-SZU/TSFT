#include <stdbool.h>

/*@ requires (1 <= (a) && (a) <= 5000 &&
      1 <= (b) && (b) <= 5000 &&
      1 <= (c) && (c) <= 10000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int train_a;
    unsigned int train_b;
    unsigned int max_val;
    unsigned int min_val;
    bool result;

    train_a = 0;
    train_b = 0;
    train_a += a;
    train_b += b;

    //@ assert train_a == a;
    //@ assert train_b == b;

    if (train_a > train_b) {
        max_val = train_a;
    } else {
        max_val = train_b;
    }

    //@ assert max_val == ((train_a) > (train_b) ? (train_a) : (train_b));

    if (train_a < train_b) {
        min_val = train_a;
    } else {
        min_val = train_b;
    }

    //@ assert min_val == ((train_a) < (train_b) ? (train_a) : (train_b));

    //@ assert max_val == train_a || max_val == train_b;
    //@ assert min_val == train_a || min_val == train_b;

    result = (max_val >= c) || (max_val + min_val >= c);

    //@ assert result == (a + b >= c);
    return result;
}
