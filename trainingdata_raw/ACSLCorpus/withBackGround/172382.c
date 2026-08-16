/*@
predicate positive(integer v) = v > 0;

lemma nonlinear_arithmetic_example_1:
    \forall integer x, y, z;
        positive(x) && positive(y) && positive(z) ==>
        x * y * z <= x * y * (z + 1);

lemma nonlinear_arithmetic_example_2:
    \forall integer a, b;
        positive(a) && positive(b) ==>
        a % b >= 0 && a % b < b;
*/

#include <stdbool.h>

/*@
    requires positive(x) && positive(y) && positive(z);
    ensures \result == true;
*/
bool verify_nonlinear_1(int x, int y, int z) {
    //@ assert positive(x) && positive(y) && positive(z);
    //@ assert x * y * z <= x * y * (z + 1);
    return true;
}

/*@
    requires positive(a) && positive(b);
    ensures \result == true;
*/
bool verify_nonlinear_2(int a, int b) {
    //@ assert positive(a) && positive(b);
    //@ assert a % b >= 0 && a % b < b;
    return true;
}

int main() {
    return 0;
}
