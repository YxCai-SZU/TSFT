/*@
    requires 1 <= n <= 100;
    ensures \result == 1 <==> (n % 2 == 0);
    assigns \nothing;
*/
int func(int n) {
    int is_even;
    int temp_n;
    
    is_even = 1;
    temp_n = n;
    
    /*@
        loop invariant (1 <= (n) <= 100 &&
        0 <= (temp_n) <= (n) &&
        ((((temp_n)) % 2) == (((n)) % 2)));
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n > 1) {
        //@ assert temp_n > 1;
        temp_n = temp_n - 2;
    }
    
    if (temp_n != 0) {
        is_even = 0;
    }
    
    //@ assert is_even == 1 <==> (n % 2 == 0);
    return is_even;
}

int main() {
    return 0;
}
