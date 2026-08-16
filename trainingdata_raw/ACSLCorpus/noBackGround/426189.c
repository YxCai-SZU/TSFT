/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    unsigned int a;
    unsigned int b;
    unsigned int c;

    a = 0;
    b = 0;
    c = 0;
    
    //@ assert ((a) <= 100) && ((b) <= 100) && ((c) <= 100);
    //@ assert ((a) * (b) <= 10000);
    
    return 0;
}
