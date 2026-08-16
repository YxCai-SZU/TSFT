/*@
requires ((((n)) >= 0) && (((n)) <= 3));
ensures \result == 1;
assigns \nothing;
*/
int func1_impl(int n) {
    //@ assert ((((n)) >= 0) && (((n)) <= 3));
    //@ assert n <= 3;
    return 1;
}

/*@
requires ((((n)) >= 0) && (((n)) <= 3));
ensures \result == 1;
assigns \nothing;
*/
int func2_impl(int n) {
    //@ assert ((((n)) >= 0) && (((n)) <= 3));
    //@ assert n <= 3;
    return 1;
}

int main() {
    return 0;
}
