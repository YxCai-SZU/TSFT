/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    int a;
    int b;
    
    //@ assert ((a) == (b)) ==> ((a) == (b + 1 - 1));
    
    return 0;
}
