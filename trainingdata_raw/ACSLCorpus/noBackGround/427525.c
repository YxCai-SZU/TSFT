#include <limits.h>

/*@
    requires INT_MIN <= 10 && 20 <= INT_MAX;
    requires INT_MIN <= -10 && 10 <= INT_MAX;
    requires INT_MIN <= 30 && 30 <= INT_MAX;
    requires INT_MIN <= 0 && 0 <= INT_MAX;
*/
void test(void) {
    //@ assert (((10) + (20)) / 2) == (10 + 20) / 2;
    //@ assert (((-10) + (10)) / 2) == (-10 + 10) / 2;
    //@ assert (((10) + (20)) / 2) <= (((20) + (30)) / 2);
    //@ assert (((-10) + (0)) / 2) <= (((0) + (10)) / 2);
}

int main(void) {
    test();
    return 0;
}
