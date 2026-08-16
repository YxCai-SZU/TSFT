#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= n * a;
    ensures \result <= b;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t min_val;
    int64_t product;

    // Precondition assertions
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;

    product = n * a;
    //@ assert product <= 1000;
    //@ assert b <= 50;

    if (product < b) {
        min_val = product;
    } else {
        min_val = b;
    }

    // Postcondition verification
    //@ assert min_val == n * a || min_val == b;
    //@ assert min_val <= n * a;
    //@ assert min_val <= b;

    return min_val;
}

int main()
{
    return 0;
}
