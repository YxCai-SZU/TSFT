
void main() {
    unsigned int x;
    unsigned int y;
    unsigned int z;
    
    // Test verify_nonlinear_inequality
    x = 5;
    y = 7;
    //@ assert x * y <= 35;
    
    // Test verify_bounds
    x = 4;
    y = 8;
    //@ assert x * y <= 32;
    
    // Test verify_congruence
    x = 10;
    y = 10;
    //@ assert x % 2 == y % 2;
    
    // Test verify_distributive
    x = 5;
    y = 8;
    z = 2;
    //@ assert x * (y + z) <= 160;
}
