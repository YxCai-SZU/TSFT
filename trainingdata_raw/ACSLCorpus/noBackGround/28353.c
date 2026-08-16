/*@
    requires \true;
    ensures \true;
*/
int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    
    //@ assert ((a) == (b));
    //@ assert ((b) == (c));
    //@ assert ((a) == (c));
    
    return 0;
}
