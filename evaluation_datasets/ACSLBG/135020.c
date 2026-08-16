/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a && a <= 10 &&
        0 <= b && b <= 10 &&
        0 <= c && c <= 10;

    lemma product_bound:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a * b <= 100;

    lemma triple_product_bound:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a * b * c <= 1000;

    lemma commutative:
        \forall integer a, b;
        0 <= a && a <= 10 && 0 <= b && b <= 10 ==> a * b == b * a;

    lemma associative:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a * (b * c) == (a * b) * c;

    lemma distributive:
        \forall integer a, b, c;
        bounds(a, b, c) ==> a * (b + c) == a * b + a * c;
*/


int nonlinear_arith_example(int a, int b, int c) {
    // Variable declarations at scope top
    int result = 0;

    /*@ assert a * b <= 100; */
    /*@ assert a * b * c <= 1000; */
    /*@ assert a * b == b * a; */
    /*@ assert a * (b * c) == (a * b) * c; */
    /*@ assert a * (b + c) == a * b + a * c; */

    return result;
}

int main() {
    return 0;
}
