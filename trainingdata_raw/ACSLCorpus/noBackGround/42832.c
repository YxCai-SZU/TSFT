/*@
    requires ((((x)) > 0) && (((y)) > 0) && (((z)) > 0) && (((w)) > 0) &&
        (((x)) <= 100) && (((y)) <= 100) && (((z)) <= 100) && (((w)) <= 100));
    ensures \result == 0;
    assigns \nothing;
*/
int nonlinear_arithmetic_example_4(int x, int y, int z, int w) {
    //@ assert ((x) > 0) && ((y) > 0) && ((z) > 0) && ((w) > 0);
    //@ assert ((x) <= 100) && ((y) <= 100) && ((z) <= 100) && ((w) <= 100);
    
    //@ assert ((x) * (y) * (z)) == (x * y) * z;
    //@ assert ((x) * ((y) + (z))) == x * y + x * z;
    //@ assert ((x) * ((y) + (w))) == x * y + x * w;
    
    //@ assert x * y * (z + w) == (x * y) * z + (x * y) * w;
    
    return 0;
}

int main() {
    return 0;
}
