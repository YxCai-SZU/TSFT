/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3);
    ensures \result == (((a) * (b)) % 2 != 0);
*/
int func(int a, int b) {
    int result;
    
    //@ assert ((a) * (b)) <= 9;
    
    result = (a * b) % 2 != 0;
    return result;
}
