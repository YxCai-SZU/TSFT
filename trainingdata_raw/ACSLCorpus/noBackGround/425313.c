/*@
    requires \true;
    ensures \result == (x * y == y * x);
    assigns \nothing;
*/
int check_multiplication_commutativity(unsigned int x, unsigned int y) {
    int result;
    
    //@ assert ((x) * (y) == (y) * (x));
    
    result = (x * y == y * x);
    return result;
}
