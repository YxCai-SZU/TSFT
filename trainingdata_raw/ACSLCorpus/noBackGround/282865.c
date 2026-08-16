/*@
    requires 0 <= a;
    requires 0 <= b;
    ensures \result == a + b;
*/
int add_non_negative(int a, int b) {
    //@ assert a >= 0;
    //@ assert b >= 0;
    int result = a + b;
    //@ assert result == a + b;
    return result;
}

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == 1;
*/
int check_bounds(int x, int y) {
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    int result = 1;
    //@ assert x <= y + 100;
    return result;
}

int main() {
    int a = 5;
    int b = 3;
    int sum = add_non_negative(a, b);
    
    int x = 50;
    int y = 60;
    int check = check_bounds(x, y);
    
    return 0;
}
