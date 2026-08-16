/*@
requires n > 0;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_7(int n) {
    int result = 0;
    
    //@ assert n > 0;
    
    //@ assert n < n + 1;
    
    //@ assert n + 1 < n + 3;
    
    //@ assert n < n + 3;
    
    return result;
}
