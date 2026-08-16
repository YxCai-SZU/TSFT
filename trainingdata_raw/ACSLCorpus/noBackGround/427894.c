/*@
    requires (0 <= (a) <= 100) && (0 <= (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int p) {
    unsigned int a2;
    unsigned int sum;
    unsigned int pies;
    
    a2 = a * 3;
    sum = a2 + p;
    
    //@ assert sum == a * 3 + p;
    
    pies = sum / 2;
    return pies;
}
