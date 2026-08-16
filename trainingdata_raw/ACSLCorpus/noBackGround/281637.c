/*@
  requires \true;
  assigns \nothing;
*/
void main() {
    // Variable declarations
    int a, b, c, x, y;
    
    // Proof block for calc_example_4
    //@ assert a < b ==> b < c ==> a < c;
    
    // Proof block for calc_example_5
    //@ assert x >= 0 && y > 0 && x < y ==> x < y;
}
