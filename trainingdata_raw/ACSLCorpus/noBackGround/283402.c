/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires ((y) % 2 == 0);
    ensures \result == x + ((y) / 2);
*/
int func(int x, int y) {
    int half_y;
    int i;
    
    half_y = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= half_y <= ((y) / 2);
        loop invariant 0 <= i <= y;
        loop invariant half_y * 2 == i;
        loop assigns half_y, i;
    */
    while (i < y) {
        //@ assert half_y < ((y) / 2);
        half_y = half_y + 1;
        i = i + 2;
    }
    
    //@ assert half_y == ((y) / 2);
    int res = x + half_y;
    return res;
}
