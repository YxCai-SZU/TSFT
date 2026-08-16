/*@
    requires x < 100;
    ensures \result == \true;
*/
int simple_calc_chain_proof(int x) {
    //@ assert x < 100;
    //@ assert x + 1 < x + 10;
    return 1;
}

/*@
    requires x < 100 && x > -100;
    ensures \result == \true;
*/
int abs_nonlinear_proof(int x) {
    //@ assert x < 100 && x > -100;
    /*@ assert
        (x >= 0 ==> x == x) &&
        (x < 0 ==> -x == -x);
    */
    return 1;
}

int main() {
    int x;
    int y;
    
    x = 50;
    //@ assert x < 100;
    simple_calc_chain_proof(x);
    
    y = -50;
    //@ assert y < 100 && y > -100;
    abs_nonlinear_proof(y);
    
    return 0;
}
