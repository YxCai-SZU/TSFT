/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 10;
    
    logic integer func(integer n) = n * n;
    
    lemma calc_example_1:
        \forall integer n; is_valid_range(n) ==> func(n) <= 100;
*/

int main() {
    return 0;
}
