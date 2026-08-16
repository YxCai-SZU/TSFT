/*@
    requires (0 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= 100 &&
        (n) * 2 <= (m));
    ensures \result == ((((m)) - ((n)) * 2) / 4);
*/
unsigned long func(unsigned long n, unsigned long m) {
    unsigned long operations;
    unsigned long operations_performed;
    unsigned long balls_left;

    //@ assert (0 <= (n) && (n) <= 100 &&         0 <= (m) && (m) <= 100 &&         (n) * 2 <= (m));
    operations = m - n * 2;
    operations_performed = operations / 4;
    
    //@ assert operations_performed == ((((m)) - ((n)) * 2) / 4);
    //@ assert operations_performed * 2 + n * 2 <= 100 * 2 + 100 * 2;
    
    balls_left = operations_performed * 2 + n * 2;
    
    return operations_performed;
}
