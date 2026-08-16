#include <stdbool.h>

/*@ requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == ((((n) + 1) / 2) >= k);
    assigns \nothing;
*/
bool func(int n, int k) {
    unsigned int n_unsigned;
    unsigned int k_unsigned;
    unsigned int half_n_unsigned;
    unsigned int next_n_unsigned;
    unsigned int half_next_n_unsigned;
    bool ans;

    n_unsigned = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
    k_unsigned = (k < 0) ? (unsigned int)(-k) : (unsigned int)k;

    half_n_unsigned = n_unsigned / 2;
    next_n_unsigned = n_unsigned + 1;
    half_next_n_unsigned = next_n_unsigned / 2;

    ans = (half_n_unsigned >= k_unsigned) || (half_next_n_unsigned >= k_unsigned);

    //@ assert ans == ((((n) + 1) / 2) >= k);

    return ans;
}
