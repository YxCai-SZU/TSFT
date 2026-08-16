/*@
requires x < y;
ensures \result == 0;
assigns \nothing;
*/
int lemma(int x, int y) {
    //@ assert x < y + 1;
    return 0;
}

/*@
requires y > 0;
ensures \result == 0;
assigns \nothing;
*/
int calc_example(int y) {
    //@ assert 0 < y;
    return 0;
}

/*@
requires x > y;
ensures \result == 0;
assigns \nothing;
*/
int lemma2(int x, int y) {
    //@ assert x - 1 > y - 1;
    return 0;
}

/*@
requires x > y;
ensures \result == 0;
assigns \nothing;
*/
int calc_example2(int x, int y) {
    //@ assert x - 1 > y - 1;
    return 0;
}

int main() {
    return 0;
}
