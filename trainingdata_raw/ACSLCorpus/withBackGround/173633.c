/*@
    logic integer sub(integer x, integer y) = x - y;
    logic integer add(integer x, integer y) = x + y;
    
    lemma calc_example_sub:
        \forall integer a, b; a >= b ==> sub(a, b) >= 0;
    
    lemma calc_example_add:
        \forall integer a, b; a >= 0 && b >= 0 && a + b <= 2147483647 ==> add(a, b) >= 0;
    
    lemma calc_example_inequality:
        \forall integer a, b; a >= b && b >= 0 && a <= 2147483647 ==> a >= b;
    
    lemma calc_example_range:
        \forall integer a, b; 0 <= a && a <= b && b <= 2147483647 ==> a >= 0 && b >= 0;
    
    lemma calc_example_chain:
        \forall integer a, b, c; a >= b && b >= c && c >= 0 && a <= 2147483647 ==> a >= c;
*/

int main() {
    return 0;
}
