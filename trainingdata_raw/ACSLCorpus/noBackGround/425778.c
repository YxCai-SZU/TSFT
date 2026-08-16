#include <stdbool.h>

/*@
    requires b * b - 4 * a * c >= 0;
    ensures \result == true;
*/
bool check_real_roots(int a, int b, int c) {
    //@ assert ((b) * (b) - 4 * (a) * (c) >= 0);
    return true;
}

int main() {
    //@ assert ((2) * (2) - 4 * (1) * (1) >= 0);
    bool result = check_real_roots(1, 2, 1);
    return 0;
}
