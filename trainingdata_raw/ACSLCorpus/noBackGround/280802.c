/*@
    requires \true;
    ensures \result == 0;
*/
int main() {
    int a = 5;
    int b = 10;
    
    //@ assert ((a) == 5 && (b) == 2 * (a));
    //@ assert b / 2 == a;
    
    return 0;
}
