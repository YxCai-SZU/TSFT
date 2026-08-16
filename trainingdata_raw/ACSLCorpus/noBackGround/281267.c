/*@
    requires \true;
    ensures \true;
*/
void main() {
    int x;
    int y;
    
    //@ assert x * (y + 2) == x * y + 2 * x;
    //@ assert x * (y + 1) == x * y + x;
    //@ assert x * (y - 1) == x * y - x;
}
