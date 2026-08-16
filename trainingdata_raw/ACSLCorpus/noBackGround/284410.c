/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures \result <= 100;
*/
int proof(int a, int b) {
    //@ assert ((1) <= (a) && (a) <= (10));
    //@ assert ((1) <= (b) && (b) <= (10));
    
    //@ assert ((1) <= (a) && (a) <= (5)) || ((6) <= (a) && (a) <= (10));
    
    if (a >= 1 && a <= 5) {
        //@ assert ((1) <= (a) && (a) <= (5));
        //@ assert ((1) <= (a*b) && (a*b) <= (50));
    } else {
        //@ assert ((6) <= (a) && (a) <= (10));
        //@ assert ((6) <= (a*b) && (a*b) <= (100));
    }
    
    //@ assert a*b <= 100;
    return a * b;
}

int main() {
    return 0;
}
