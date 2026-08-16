/*@
    requires ((x) > 0 && (a) > 0 && (b) > 0 &&
        (x) <= 100 && (a) <= 100 && (b) <= 100);
    ensures \result >= 0;
    ensures \result <= x * (a + b);
    assigns \nothing;
*/
int non_linear_arith_example(int x, int a, int b) {
    //@ assert ((x) > 0 && (a) > 0 && (b) > 0 &&         (x) <= 100 && (a) <= 100 && (b) <= 100);
    
    //@ assert x * (a + b) >= 0;
    //@ assert x * (a + b) <= 100 * 200;
    //@ assert x * (a + b) == x * a + x * b;
    
    int result = x * (a + b);
    //@ assert result >= 0;
    //@ assert result <= x * (a + b);
    
    return result;
}
