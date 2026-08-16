/*@
    requires 0 <= n && n <= 100;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
int is_even_func(int n) {
    //@ assert 0 <= n && n <= 100;
    return n % 2 == 0;
}

int main() {
    int a = 5;
    int b = 5;
    int c = 5;
    
    //@ assert a == b && b == c;
    //@ assert a == c;
    
    int n = 42;
    //@ assert 0 <= n && n <= 100;
    
    int result = is_even_func(n);
    //@ assert result == (n % 2 == 0);
    
    return 0;
}
