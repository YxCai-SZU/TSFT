/*@
    requires \true;
    ensures \true;
*/
int main() {
    //@ assert ((0) <= 0 ? 0 : (0) * (0) * (0)) == 0;
    //@ assert ((1) <= 0 ? 0 : (1) * (1) * (1)) == 1;
    //@ assert ((2) <= 0 ? 0 : (2) * (2) * (2)) == 8;
    //@ assert ((3) <= 0 ? 0 : (3) * (3) * (3)) == 27;
    
    return 0;
}
