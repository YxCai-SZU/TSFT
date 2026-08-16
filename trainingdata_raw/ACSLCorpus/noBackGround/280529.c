#include <stdbool.h>

/*@ requires (1 <= (x) && (x) <= 3);
    ensures \true; */
void proof_is_between_1_and_3(int x) {
    //@ assert 1 <= x && x <= 3;
    //@ assert x == 1 || x == 2 || x == 3;
}

/*@ requires x == y;
    ensures \true; */
void proof_calc_example_16(int x, int y) {
    //@ assert x == y;
    //@ assert x == y + 1 - 1;
}

/*@ requires ((x) > 0);
    ensures \true; */
void proof_is_positive(int x) {
    //@ assert x > 0;
}

/*@ requires ((x) % 2 == 0);
    ensures \true; */
void proof_is_even(int x) {
    //@ assert x % 2 == 0;
}

int main() {
    return 0;
}
