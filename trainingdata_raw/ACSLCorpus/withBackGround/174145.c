/*@
predicate a_less_b_less_c(integer a, integer b, integer c) =
    a < b && b < c;

logic integer diff(integer x, integer y) = x - y;
logic integer sum(integer x, integer y) = x + y;

lemma calc_example_3:
    \forall integer a, b, c;
    a_less_b_less_c(a, b, c) ==>
    sum(a, diff(c, b)) == diff(c, diff(b, a));

lemma lemma_even_difference_is_even:
    \forall integer n;
    n % 2 == 0 ==> (n - 2) % 2 == 0;
*/

int main() {
    int a;
    int b;
    int c;
    
    //@ assert a < b && b < c ==> a + (c - b) == c - (b - a);
    
    return 0;
}
