/*@
requires a + b >= 5 && b + c >= 7 && c + a >= 9;
ensures \result >= 10;
assigns \nothing;
*/
int calc_example(int a, int b, int c) {
    //@ assert a + b >= 5 && b + c >= 7 && c + a >= 9;
    //@ assert a + b + c >= 10;
    return a + b + c;
}

/*@
requires a >= 0 && b >= 0;
ensures \result >= 0;
assigns \nothing;
*/
int lemma_sum(int a, int b) {
    //@ assert a >= 0 && b >= 0;
    //@ assert a + b >= 0;
    return a + b;
}

/*@
requires a >= 0 && b >= 0 && c >= 0;
ensures \result >= 0;
assigns \nothing;
*/
int lemma_triple_sum(int a, int b, int c) {
    //@ assert a >= 0 && b >= 0 && c >= 0;
    //@ assert a + b >= 0 && b + c >= 0;
    //@ assert a + b + c >= 0;
    return a + b + c;
}

int main() {
    return 0;
}
