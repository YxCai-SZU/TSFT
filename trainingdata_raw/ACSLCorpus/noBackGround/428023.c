/*@
    requires a < 0x80000000;
    requires b < 0x80000000;
    ensures \result == a + b;
    ensures ((a) < 0x80000000 && (b) < 0x80000000 && (\result) == (a) + (b));
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int sum;

    //@ assert a < 0x80000000;
    //@ assert b < 0x80000000;
    
    //@ assert a + b < 0x100000000;
    
    sum = a + b;
    
    //@ assert sum == a + b;
    
    return sum;
}
