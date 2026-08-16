/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b % 2 != 0);
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at top
    int result;
    
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert 1 <= a * b && a * b <= 9;
    
    if ((a == 1 || a == 3) && (b == 1 || b == 3)) {
        //@ assert ((a) % 2 != 0) && ((b) % 2 != 0);
        //@ assert ((a * b) % 2 != 0);
        result = 1;
    } else if ((a == 2 && (b == 1 || b == 3)) || 
               (b == 2 && (a == 1 || a == 3))) {
        //@ assert ((a) % 2 == 0) || ((b) % 2 == 0);
        //@ assert ((a * b) % 2 == 0);
        result = 0;
    } else {
        //@ assert a == 2 && b == 2;
        //@ assert ((a * b) % 2 == 0);
        result = 0;
    }
    
    return result;
}

int main() {
    return 0;
}
