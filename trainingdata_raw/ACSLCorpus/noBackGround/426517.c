/*@
requires 0 <= x < 10;
ensures \result <= 10;
assigns \nothing;
*/
int different_relations_impl(int x) {
    //@ assert x >= 0;
    //@ assert x < 10;
    //@ assert x <= 10;
    return x;
}

/*@
requires 0 <= x < 5;
ensures \result <= 5;
assigns \nothing;
*/
int multiple_steps_impl(int x) {
    //@ assert x >= 0;
    //@ assert x < 5;
    //@ assert x <= 5;
    return x;
}

/*@
requires 0 <= x < 2;
ensures \result <= 2;
assigns \nothing;
*/
int no_repeated_expressions_impl(int x) {
    //@ assert x >= 0;
    //@ assert x < 2;
    //@ assert x <= 2;
    return x;
}

int main() {
    return 0;
}
