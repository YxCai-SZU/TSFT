/*@
    requires (1 <= (x) <= 179);
    ensures (((\result) == 0 || (\result) == 1) && 
        ((\result) == 1 ==> 1 <= (x) <= 179) && 
        ((\result) == 0 ==> 1 <= (x) <= 179));
*/
int func(int x) {
    int c;
    int s;
    int result;
    
    c = 1;
    s = 0;
    
    /*@
        loop invariant 1 <= c <= 101;
        loop invariant s == (3 * ((c) - 1));
        loop invariant (1 <= (x) <= 179);
        loop assigns c, s;
    */
    while (c <= 100) {
        //@ assert 1 <= c <= 100;
        s += 3;
        c += 1;
    }
    
    //@ assert c == 101;
    //@ assert s == 300;
    
    if (x >= s - 1 && x <= s) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert (((result) == 0 || (result) == 1) &&          ((result) == 1 ==> 1 <= (x) <= 179) &&          ((result) == 0 ==> 1 <= (x) <= 179));
    return result;
}
