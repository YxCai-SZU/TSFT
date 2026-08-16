/*@
    requires n >= 0;
    ensures \result == n * n + 5;
    assigns \nothing;
*/
int example_6_function(int n) {
    int result;
    //@ assert n * n >= 0;
    //@ assert n * n + 3 >= n * n;
    //@ assert n * n + 4 >= n * n + 3;
    //@ assert n * n + 5 >= n * n + 4;
    result = n * n + 5;
    return result;
}

int main() {
    return 0;
}
