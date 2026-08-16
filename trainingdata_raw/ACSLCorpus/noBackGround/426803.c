/*@
    requires a > 0;
    ensures \result == 1;
*/
int is_positive_func(int a) {
    //@ assert a > 0;
    return 1;
}

int main() {
    int a = 5;
    int b = 10;
    
    //@ assert a < b;
    //@ assert a - 1 < b - 1;
    
    int result = is_positive_func(a);
    //@ assert result == 1;
    
    return 0;
}
