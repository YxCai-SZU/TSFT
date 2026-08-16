/*@
    requires (1000 <= (n) && (n) <= 9999);
    ensures ((\result) == ((n) % 5 == 0 || (n) % 3 == 0 || (n) % 5 == 3 || (n) % 3 == 2));
    assigns \nothing;
*/
int func(int n) {
    int result;
    
    if (n % 5 == 0 || n % 3 == 0) {
        //@ assert n % 5 == 0 || n % 3 == 0 || n % 5 == 3 || n % 3 == 2;
        result = 1;
    } else if (n % 5 == 3 || n % 3 == 2) {
        //@ assert n % 5 == 0 || n % 3 == 0 || n % 5 == 3 || n % 3 == 2;
        result = 1;
    } else {
        //@ assert !(n % 5 == 0 || n % 3 == 0 || n % 5 == 3 || n % 3 == 2);
        result = 0;
    }
    
    return result;
}
