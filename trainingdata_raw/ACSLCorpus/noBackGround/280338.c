/*@
    requires 1 <= x <= 10;
    requires 1 <= y <= 10;
    ensures \result == 1;
    assigns \nothing;
*/
int check_bounds(int x, int y) {
    //@ assert x <= 10;
    //@ assert y <= 10;
    //@ assert 2 * x + y <= 2 * 10 + 10;
    //@ assert 2 * 10 + 10 <= 30;
    return 1;
}

int main() {
    int x = 5;
    int y = 5;
    int result;
    
    //@ assert 1 <= x <= 10;
    //@ assert 1 <= y <= 10;
    result = check_bounds(x, y);
    //@ assert result == 1;
    return 0;
}
