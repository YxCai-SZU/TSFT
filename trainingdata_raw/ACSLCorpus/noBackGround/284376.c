/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) * 800 - (((a)) / 3) * 200);
    assigns \nothing;
*/
int func(unsigned int a) {
    unsigned int x;
    int result;

    //@ assert (1 <= (a) && (a) <= 10);
    
    x = a / 3;
    //@ assert x == ((a) / 3);
    
    result = a * 800 - x * 200;
    //@ assert result == ((a) * 800 - (((a)) / 3) * 200);
    
    //@ assert result == a * 800 - (a / 3) * 200;
    
    return result;
}
