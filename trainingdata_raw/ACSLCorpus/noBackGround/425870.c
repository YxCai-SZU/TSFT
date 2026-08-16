/*@
    requires (-1290 <= (x) && (x) <= 1290);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int func(int x) {
    int cube;
    
    //@ assert (-1290 <= (x) && (x) <= 1290);
    //@ assert -1290 * 1290 <= x * x && x * x <= 1290 * 1290;
    //@ assert -1290 * 1290 * 1290 <= x * x * x && x * x * x <= 1290 * 1290 * 1290;
    
    cube = x * x * x;
    
    //@ assert cube == x * x * x;
    return cube;
}
