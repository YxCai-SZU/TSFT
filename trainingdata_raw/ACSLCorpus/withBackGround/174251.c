/*@
    predicate pos(integer x) = x > 0;

    lemma non_linear_arith_example16:
        \forall integer a, b; pos(a) && pos(b) ==> (a - b) * b == a * b - b * b;

    lemma non_linear_arith_example17:
        \forall integer a, b; pos(a) && pos(b) ==> (a + b) * b == a * b + b * b;

    lemma non_linear_arith_example18:
        \forall integer a, b; pos(a) && pos(b) ==> (a * b) * b == a * (b * b);

    lemma non_linear_arith_example19:
        \forall integer a, b, c; pos(a) && pos(b) && pos(c) ==> (a * b) * c == a * (b * c);

    lemma non_linear_arith_example20:
        \forall integer a, b, c; pos(a) && pos(b) && pos(c) ==> (a * b) * c == a * (b * c);
*/

int main() {
    int a;
    int b;
    int c;
    
    //@ assert \true;
    
    return 0;
}
