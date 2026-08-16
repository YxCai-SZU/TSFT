/*@
    requires 1 <= n <= 10;
    ensures \result == n * n;
    assigns \nothing;
*/
int func_impl(int n) {
    int result;
    result = n * n;
    //@ assert result == n * n;
    return result;
}

int main() {
    int a = 5;
    int b = 8;
    int min_val;
    int max_val;
    int func_val;

    // Verify min property
    //@ assert a <= b;
    min_val = (a < b) ? a : b;
    //@ assert min_val <= b;

    // Verify max property
    //@ assert a <= b;
    max_val = (a > b) ? a : b;
    //@ assert a <= max_val;

    // Verify func property
    func_val = func_impl(a);
    //@ assert func_val >= 1;

    return 0;
}
