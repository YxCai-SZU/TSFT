/*@
requires x + 2 == y;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_2(int x, int y) {
    //@ assert x <= y;
    return 0;
}

/*@
requires x < y;
ensures \result == 0;
assigns \nothing;
*/
int mixed_relations(int x, int y) {
    //@ assert x + 1 <= y + 2;
    return 0;
}

/*@
requires x < y;
ensures \result == 0;
assigns \nothing;
*/
int non_trivial_steps(int x, int y) {
    //@ assert x + 1 <= y + 2;
    return 0;
}

/*@
requires x < y;
ensures \result == 0;
assigns \nothing;
*/
int trivial_steps(int x, int y) {
    //@ assert x + 1 <= y + 2;
    return 0;
}

int main() {
    return 0;
}
