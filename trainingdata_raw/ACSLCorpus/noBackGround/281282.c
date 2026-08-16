#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n / 10 == 9 || n % 10 == 9);
    assigns \nothing;
*/
bool func(unsigned long long n) {
    unsigned int n_unsigned;
    bool result;

    n_unsigned = (unsigned int)n;
    //@ assert n_unsigned == n;

    result = (n_unsigned / 10 == 9 || n_unsigned % 10 == 9);
    return result;
}

int main() {
    return 0;
}
