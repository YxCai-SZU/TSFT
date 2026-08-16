/*@
    lemma mul_commutative: \forall integer x, integer y; x * y == y * x;
    lemma mul_associative: \forall integer x, integer y, integer z; x * (y * z) == (x * y) * z;
    lemma mul_distributive_add: \forall integer x, integer y, integer z; x * (y + z) == x * y + x * z;
*/

/*@
    requires 0 <= a && a <= 10;
    requires 0 <= b && b <= 10;
    ensures \result <= 100;
*/
unsigned int multiplication_check(unsigned int a, unsigned int b) {
    //@ assert a * b <= 100;
    return a * b;
}

/*@
    requires 0 <= a && a <= 8;
    requires 0 <= b && b <= 8;
    ensures \result <= 64;
*/
unsigned int multiplication_check2(unsigned int a, unsigned int b) {
    //@ assert a * b <= 64;
    return a * b;
}

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    ensures \result <= 10000;
*/
unsigned int multiplication_check3(unsigned int a, unsigned int b) {
    //@ assert a * b <= 10000;
    return a * b;
}

int main() {
    return 0;
}
