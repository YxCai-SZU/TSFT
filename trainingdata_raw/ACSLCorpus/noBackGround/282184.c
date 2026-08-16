/*@
    requires ((s) >= 2);
    ensures \result == ((((s))));
*/
int calc_example_g(int s) {
    //@ assert ((s) > 0);
    //@ assert ((((s)))) == s;
    return s;
}

/*@
    requires a == a;
    ensures \true;
*/
void lemma_identity(int a) {
    //@ assert a == a;
}

/*@
    requires a + b == a + b;
    ensures a + b == b + a;
*/
void lemma_addition_commutative(int a, int b) {
    //@ assert a + b == b + a;
}

/*@
    requires a + b + c == a + b + c;
    ensures a + b + c == (a + b) + c;
*/
void lemma_addition_associative(int a, int b, int c) {
    //@ assert a + b + c == (a + b) + c;
}

/*@
    requires a + b + c == a + b + c;
    ensures a + b + c == (b + a) + c;
*/
void lemma_addition_commutes_into_assoc(int a, int b, int c) {
    //@ assert a + b + c == (b + a) + c;
}

/*@
    requires a + b + c == a + b + c;
    ensures a + b + c == (b + a) + c;
*/
void lemma_commutes_into_assoc(int a, int b, int c) {
    //@ assert a + b + c == (b + a) + c;
}

/*@
    requires a + b + c == a + b + c;
    ensures a + b + c == (a + b) + c;
*/
void lemma_assoc(int a, int b, int c) {
    //@ assert a + b + c == (a + b) + c;
}

/*@
    requires a + b == a + b;
    ensures a + b == b + a;
*/
void lemma_commutes(int a, int b) {
    //@ assert a + b == b + a;
}

/*@
    requires a + b + c == a + b + c;
    ensures a + b + c == (b + a) + c;
*/
void lemma_assoc_into_commutes(int a, int b, int c) {
    //@ assert a + b + c == (b + a) + c;
}

/*@
    requires a + b + c == a + b + c;
    ensures a + b + c == (b + a) + c;
*/
void lemma_commutes_into_assoc_commutes(int a, int b, int c) {
    //@ assert a + b + c == (b + a) + c;
}

/*@
    requires a + b + c == a + b + c;
    ensures a + b + c == (b + a) + c;
*/
void lemma_commutes_assoc_into_commutes_assoc(int a, int b, int c) {
    //@ assert a + b + c == (b + a) + c;
}

int main() {
    return 0;
}
