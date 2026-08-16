/*@
    predicate test_bool(integer a) = a == 0;
    
    lemma calc_example_8:
        \forall integer a; test_bool(a) ==> a == 0;
*/

int main() {
    //@ assert test_bool(0);
    return 0;
}
