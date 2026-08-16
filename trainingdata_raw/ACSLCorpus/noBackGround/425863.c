/*@
    requires ((x) >= 0);
    ensures (2 * ((x) + 2) <= 2 * (x) + 20);
    assigns \nothing;
*/
void calc_example_1(int x) {
    //@ assert 2 * (x + 2) == 2 * x + 4;
    //@ assert 2 * x + 4 <= 2 * x + 20;
}

/*@
    requires (2 * ((x) + 2) <= 2 * (x) + 20);
    ensures 2 * x + 4 <= 2 * x + 20;
    assigns \nothing;
*/
void lemma_1(int x) {
    //@ assert 2 * (x + 2) == 2 * x + 4;
}

/*@
    requires 2 * x + 4 <= 2 * x + 20;
    ensures 2 * x + 4 <= 2 * x + 20;
    assigns \nothing;
*/
void lemma_2(int x) {
    //@ assert 2 * x + 4 <= 2 * x + 20;
}

/*@
    requires 2 * x + 4 <= 2 * x + 20;
    ensures (2 * ((x) + 2) <= 2 * (x) + 20);
    assigns \nothing;
*/
void lemma_3(int x) {
    //@ assert 2 * (x + 2) == 2 * x + 4;
}

int main() {
    return 0;
}
