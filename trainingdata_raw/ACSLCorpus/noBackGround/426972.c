/*@
    requires (1 <= (n) && (n) <= 5);
    ensures \result == 1;
    assigns \nothing;
*/
int func(int n) {
    //@ assert (1 <= (n) && (n) <= 5);
    //@ assert n + 3 <= 8;
    return 1;
}

/*@
    requires (1 <= (n) && (n) <= 5);
    ensures \result == 1;
    assigns \nothing;
*/
int func2(int n) {
    //@ assert (1 <= (n) && (n) <= 5);
    //@ assert 8 <= n + 3 + 5;
    return 1;
}

/*@
    requires (1 <= (n) && (n) <= 5);
    ensures \result == 1;
    assigns \nothing;
*/
int func3(int n) {
    //@ assert (1 <= (n) && (n) <= 5);
    //@ assert n + 3 <= 8 + 3 + 5;
    return 1;
}

int main() {
    return 0;
}
