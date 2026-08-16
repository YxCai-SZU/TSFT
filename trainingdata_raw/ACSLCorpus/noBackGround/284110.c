/*@
requires 0 <= x && x <= 1;
requires 0 <= y && y <= 1;
ensures 0 <= \result;
ensures \result <= 1;
*/
int func(int x, int y) {
    int result;
    
    //@ assert 0 <= x && x <= 1;
    //@ assert 0 <= y && y <= 1;
    
    //@ ghost product_nonnegative: 0 <= x * y;
    //@ assert 0 <= x * y;
    
    result = x * y;
    
    //@ ghost product_within_unit: x * y <= 1;
    //@ assert result <= 1;
    
    return result;
}
