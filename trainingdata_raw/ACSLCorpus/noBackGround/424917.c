/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * 2 - (b) * 2) >= 0);
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    sum = a * 2 - b * 2;
    
    //@ assert sum == ((a) * 2 - (b) * 2);
    
    return sum >= 0;
}
