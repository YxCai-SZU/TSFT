#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
*/
bool func(long r, long g, long b)
{
    // Variable declarations at top of scope
    long sum;
    bool is_divisible = false;
    long abs_sum;
    long remainder;

    //@ assert 111 <= r * 100 + g * 10 + b <= 999;

    sum = r * 100 + g * 10 + b;
    abs_sum = sum;

    // Implement absolute value manually
    if (sum < 0) {
        abs_sum = -sum;
    }

    remainder = abs_sum;
    /*@
        loop invariant 0 <= remainder <= abs_sum;
        loop invariant remainder % 4 == abs_sum % 4;
        loop assigns remainder;
    */
    while (remainder >= 4) {
        remainder -= 4;
    }

    if (remainder == 0) {
        is_divisible = true;
    }

    //@ assert is_divisible == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
    return is_divisible;
}

int main() {
    return 0;
}
