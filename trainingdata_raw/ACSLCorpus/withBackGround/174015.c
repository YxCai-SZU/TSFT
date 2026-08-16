/*@
  axiomatic K {
    logic integer k(integer n);
    logic integer abs(integer n);
    
    axiom k_add_inequality: k(1) == k(3);
    axiom k_diff_inequality: k(1) == k(5);
    axiom k_copy_inequality: k(1) == k(9);
    
    lemma example_1: k(9) == k(9) ==> k(1) == k(9);
    lemma example_2: k(9) == k(9) ==> k(9) == k(1);
  }
*/

int main() {
    return 0;
}
