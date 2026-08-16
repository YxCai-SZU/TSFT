#include <stdbool.h>

/*@
    logic integer cube_spec(integer k) = k * k * k;

    lemma cube_spec_definition:
        \forall integer k; cube_spec(k) == k * k * k;

    lemma cube_spec_bounds:
        \forall integer k; -10 <= k <= 10 ==> -1000 <= cube_spec(k) <= 1000;
*/


int compute_cube(int k) {
    //@ assert cube_spec(k) == k * k * k;
    //@ assert -10 <= k <= 10;
    //@ assert -1000 <= k * k * k <= 1000;
    int result = k * k * k;
    //@ assert result == cube_spec(k);
    //@ assert result >= -1000;
    //@ assert result <= 1000;
    return result;
}

/*@
    lemma test_cuber_values:
        cube_spec(2) == 8 &&
        cube_spec(-3) == -27 &&
        cube_spec(0) == 0 &&
        cube_spec(-5) == -125 &&
        cube_spec(6) == 216;
*/

int main() {
    return 0;
}
