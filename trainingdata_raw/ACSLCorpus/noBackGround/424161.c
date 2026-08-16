#include <stdint.h>

/*@ assigns \nothing; */
void test_non_linear_arith_example10(void) {
    int a;
    int b;
    int result;

    a = 10;
    b = 2;
    result = (a * b) / b;

    //@ assert result == a;
}

/*@ assigns \nothing; */
void test_non_linear_arith_example11(void) {
    int a;
    int b;
    int result;

    a = 10;
    b = 2;
    result = (a * b) / b;

    //@ assert result == a;
}

/*@ assigns \nothing; */
void test_bound_check(void) {
    uint32_t x;
    uint32_t y;
    uint32_t result;

    x = 5;
    y = 5;
    result = x * y;

    //@ assert result <= 1000;
}

/*@ assigns \nothing; */
void test_bound_check2(void) {
    uint32_t x;
    uint32_t y;
    uint32_t result;

    x = 5;
    y = 5;
    result = x * y;

    //@ assert result <= 64;
}

/*@ assigns \nothing; */
int main(void) {
    test_non_linear_arith_example10();
    test_non_linear_arith_example11();
    test_bound_check();
    test_bound_check2();
    return 0;
}
