/*@
    predicate positive(integer a) = a > 0;
    predicate at_least_one(integer a) = a >= 1;
    predicate cube_ge_original(integer a) = a * a * a >= a;
    predicate half_less_original(integer x) = x / 2 < x;
    
    lemma nonlinear_arith_exp_1: \forall integer a; positive(a) && at_least_one(a) ==> cube_ge_original(a);
    lemma div_example: \forall integer x; positive(x) ==> half_less_original(x);
*/

/*@
    requires positive(a);
    ensures cube_ge_original(a);
*/
void nonlinear_arith_exp_1(int a) {
    //@ assert positive(a);
    //@ assert at_least_one(a);
    //@ assert cube_ge_original(a);
}

/*@
    requires positive(x);
    ensures half_less_original(x);
*/
void div_example(int x) {
    //@ assert half_less_original(x);
}

int main() {
    return 0;
}
