#include <stdbool.h>

/*@
    requires -128 <= threshold <= 127;
    requires -128 <= x <= 127;
    ensures \result == (x > threshold);
    assigns \nothing;
*/
bool greater_than_threshold(int x, int threshold) {
    //@ assert -128 <= x <= 127;
    //@ assert -128 <= threshold <= 127;
    return x > threshold;
}

/*@
    requires -128 <= x <= 127;
    assigns \nothing;
*/
void print_result(int x) {
    //@ assert -128 <= x <= 127;
    //@ assert \true;
}

/*@
    assigns \nothing;
*/
int main() {
    int n = 10;
    //@ assert n == 10;
    print_result(n);
    return 0;
}
