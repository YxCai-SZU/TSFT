/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    int a;
    int b;
    int c;
    
    //@ ghost int a_val = a;
    //@ ghost int b_val = b;
    //@ ghost int c_val = c;
    
    //@ assert (0 <= (a_val) <= 100 && 0 <= (b_val) <= 100 && 0 <= (c_val) <= 100) ==> a_val <= ((a_val) + (b_val) + (c_val));
    
    return 0;
}
