/*@
    requires ((a) > 0 && (b) > 0);
    requires ((a) + (b) <= 100);
    ensures ((a) + (b) <= 200);
*/
void func(int a, int b) {
    // Variable declarations at top
    
    //@ assert ((a) > 0 && (b) > 0);
    //@ assert ((a) + (b) <= 100);
    //@ assert ((a) + (b) <= 200);
}
