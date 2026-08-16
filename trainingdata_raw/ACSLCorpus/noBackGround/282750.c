/*@
    requires ((a) > 0) && ((a) <= 1000);
    requires ((b) > 0) && ((b) <= 1000);
    requires ((c) > 0) && ((c) <= 1000);
    ensures \result == (a * b <= c);
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int product;
    int result;
    
    //@ assert ((a) > 0) && ((a) <= 1000);
    //@ assert ((b) > 0) && ((b) <= 1000);
    
    // Proof of multiplication bound using lemma
    //@ assert a * b <= 1000000;
    
    product = a * b;
    result = (product <= c);
    
    return result;
}
