/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    ensures \result == (((a) * (b)) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int product;
    unsigned int half_product;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    //@ assert a * b <= 10000;
    
    product = a * b;
    half_product = product / 2;
    
    return half_product;
}
