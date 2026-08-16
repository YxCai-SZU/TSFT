/*@
    requires x >= 10;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_h(int x) {
    //@ assert x - 2 <= x + 3;
    return 0;
}

/*@
    requires x >= 3;
    ensures \result == 0;
    assigns \nothing;
*/
int check_triangular(int x) {
    //@ assert x >= 3;
    return 0;
}

/*@
    requires x >= 1 && y >= 1 && x + y <= 10;
    ensures \result == 0;
    assigns \nothing;
*/
int property(int x, int y) {
    int sum;
    int is_even;
    
    sum = x + y;
    is_even = 0;
    
    if (sum % 2 == 0) {
        is_even = 1;
    }
    
    //@ assert is_even == 1 || is_even == 0;
    return 0;
}

int main() {
    return 0;
}
