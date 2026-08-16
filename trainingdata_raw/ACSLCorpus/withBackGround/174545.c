/*@
    predicate less_than_range(integer n) =
        0 <= n && n <= 100;
        
    lemma prove_less_than:
        \forall integer n; less_than_range(n) ==> 0 <= n && n < 101;
*/

int main() {
    //@ assert \true;
    return 0;
}
