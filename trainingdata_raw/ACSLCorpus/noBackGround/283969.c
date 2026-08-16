/*@
    requires 1 <= a && a <= 10;
    ensures \result == a * (1 + a + a * a);
    ensures 1 <= \result && \result <= 10 * (1 + 10 + 10 * 10);
*/
unsigned int func(unsigned int a)
{
    unsigned int a1;
    unsigned int a2;
    unsigned int a3;
    unsigned int result;
    
    //@ assert (1 <= (a) && (a) <= 10);
    
    // Bounds for a * a
    //@ assert 1 <= a;
    //@ assert a <= 10;
    //@ assert 1 <= a * a && a * a <= 10 * 10;
    
    // Bounds for a * a * a
    //@ assert 1 <= a;
    //@ assert a <= 10;
    //@ assert 1 <= a * a * a && a * a * a <= 10 * 10 * 10;
    
    // Bounds for 1 + a + a * a + a * a * a
    //@ assert 1 <= 1 + a;
    //@ assert 1 + a <= 1 + 10;
    //@ assert 1 <= a * a;
    //@ assert a * a <= 10 * 10;
    //@ assert 1 <= a * a * a;
    //@ assert a * a * a <= 10 * 10 * 10;
    //@ assert 1 <= 1 + a + a * a;
    //@ assert 1 + a + a * a <= 1 + 10 + 10 * 10;
    //@ assert 1 <= 1 + a + a * a + a * a * a && 1 + a + a * a + a * a * a <= 1 + 10 + 10 * 10 + 10 * 10 * 10;
    
    a1 = a;
    a2 = a * a;
    a3 = a * a * a;
    result = a * (1 + a + a * a);
    
    //@ assert result == ((a) * (1 + (a) + (a) * (a)));
    //@ assert 1 <= result && result <= 10 * (1 + 10 + 10 * 10);
    
    return result;
}

int main()
{
    return 0;
}
