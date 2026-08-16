/*@
    requires x >= 0;
    ensures \result >= x;
    assigns \nothing;
*/
int calc_example_3_c(int x) {
    int result;
    result = x * 2;
    //@ assert result >= x;
    return result;
}

/*@
    requires x >= 0 && y >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int calc_example_4_c(int x, int y) {
    int result;
    result = x + y;
    //@ assert result >= 0;
    return result;
}

/*@
    requires x >= 0 && y >= 0 && z >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int lemma_example_5_c(int x, int y, int z) {
    int result;
    result = x * y * z;
    //@ assert result >= 0;
    return result;
}

/*@
    requires x >= 0 && y >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int lemma_example_6_c(int x, int y) {
    int result;
    result = x + y;
    //@ assert result >= 0;
    return result;
}

/*@
    requires x >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int lemma_example_7_c(int x) {
    int result;
    result = x * 3;
    //@ assert result >= 0;
    return result;
}

/*@
    requires x >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int lemma_example_8_c(int x) {
    int result;
    result = x * 2;
    //@ assert result >= 0;
    return result;
}

/*@
    requires x >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int lemma_example_9_c(int x) {
    int result;
    result = x * 5;
    //@ assert result >= 0;
    return result;
}

/*@
    requires x >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int lemma_example_10_c(int x) {
    int result;
    result = x * 7;
    //@ assert result >= 0;
    return result;
}

/*@
    requires x >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int lemma_example_11_c(int x) {
    int result;
    result = x * 9;
    //@ assert result >= 0;
    return result;
}

int main() {
    return 0;
}
