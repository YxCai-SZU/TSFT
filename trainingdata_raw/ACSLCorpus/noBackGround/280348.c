#include <stdbool.h>

/*@
    requires a > 0 && b > 0 && a + b <= 100;
    ensures \result == a + b;
    ensures \result == 2 * (a + b) / 2;
*/
int complex_calc_example_1_impl(int a, int b) {
    int sum;
    int tmp;

    sum = a + b;
    //@ assert sum > 0;
    //@ assert sum <= 100;
    tmp = 2 * sum;
    //@ assert tmp / 2 == sum;
    return sum;
}

/*@
    requires a > 0 && b > 0 && a + b <= 100;
    ensures \result == a * 2;
    ensures \result == 2 * a;
*/
int complex_calc_example_2_impl(int a, int b) {
    int result;

    result = a * 2;
    //@ assert result == 2 * a;
    return result;
}

/*@
    requires a > 0 && b > 0 && a + b <= 100;
    ensures \result == a * 3;
    ensures \result == 3 * a;
*/
int complex_calc_example_3_impl(int a, int b) {
    int result;

    result = a * 3;
    //@ assert result == 3 * a;
    return result;
}

/*@
    requires a > 0 && b > 0 && a + b <= 100;
    ensures \result == a * 4;
    ensures \result == 4 * a;
*/
int complex_calc_example_4_impl(int a, int b) {
    int result;

    result = a * 4;
    //@ assert result == 4 * a;
    return result;
}

int main() {
    return 0;
}
