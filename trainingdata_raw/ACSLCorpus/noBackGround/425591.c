/*@
requires -40 <= n <= 40;
ensures \result == (n >= 30);
assigns \nothing;
*/
int func(int n) {
    int result;
    
    //@ assert n >= 30 ==> n >= 30;
    
    if (n >= 30) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
