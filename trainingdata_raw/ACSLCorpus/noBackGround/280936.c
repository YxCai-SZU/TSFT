/*@
    requires (0 <= (a) < 100 && 0 <= (b) < 100 && (a) > (b));
    ensures \result == 1;
    assigns \nothing;
*/
int example_func(int a, int b) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert a > b;
    
    result = 1;
    return result;
}

int main() {
    return 0;
}
