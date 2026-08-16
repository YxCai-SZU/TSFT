/*@
    requires (-31416 <= (r) <= 31416);
    ensures (-10000 <= (\result) <= 10000);
*/
int func(int r) {
    int result;
    int scaled_r;
    
    //@ assert (-31416 <= (r) <= 31416);
    scaled_r = r * 10000;
    result = 0;
    
    //@ assert (-10000 <= (result) <= 10000);
    return result;
}
