/*@
predicate bounds_1(integer x, integer y, integer z) =
    0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10;

predicate bounds_2(integer x, integer y, integer z) =
    0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;

lemma mul_bound_1:
    \forall integer x, y, z;
    bounds_1(x, y, z) ==> x * y <= 100;

lemma mul_bound_2:
    \forall integer x, y, z;
    bounds_1(x, y, z) ==> x * z <= 100;

lemma mul_bound_3:
    \forall integer x, y, z;
    bounds_1(x, y, z) ==> y * z <= 100;

lemma mul_bound_4:
    \forall integer x, y, z;
    bounds_2(x, y, z) ==> x * y <= 64;

lemma mul_bound_5:
    \forall integer x, y, z;
    bounds_2(x, y, z) ==> x * z <= 64;

lemma mul_bound_6:
    \forall integer x, y, z;
    bounds_2(x, y, z) ==> y * z <= 64;
*/

void main() {
    // Empty main as per original code
}

/*@
    requires 0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10;
    ensures \result == 0;
    ensures x * y <= 100;
    ensures x * z <= 100;
    ensures y * z <= 100;
*/
int lemma_bounds_check(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert bounds_1(x, y, z);
    //@ assert x * y <= 100;
    //@ assert x * z <= 100;
    //@ assert y * z <= 100;
    return 0;
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures \result == 0;
    ensures x * y <= 64;
    ensures x * z <= 64;
    ensures y * z <= 64;
*/
int lemma_bounds_check2(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert bounds_2(x, y, z);
    //@ assert x * y <= 64;
    //@ assert x * z <= 64;
    //@ assert y * z <= 64;
    return 0;
}
