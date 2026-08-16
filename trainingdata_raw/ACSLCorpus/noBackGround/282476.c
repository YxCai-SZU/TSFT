/*@
    requires \true;
    ensures \result == ((x & 1) == 0);
    assigns \nothing;
*/
int test_is_even(int x) {
    int result;
    //@ assert (x & 1) == 0 ==> (x & 1) == 0;
    result = (x & 1) == 0;
    return result;
}

/*@
    requires \true;
    ensures \result == ((x & 1) != 0);
    assigns \nothing;
*/
int test_is_odd(int x) {
    int result;
    //@ assert (x & 1) != 0 ==> (x & 1) != 0;
    result = (x & 1) != 0;
    return result;
}

int main() {
    return 0;
}
