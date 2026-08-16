/*@
predicate is_multiple_of_3(integer x) = x % 3 == 0;

lemma multiple_of_3:
    \forall integer x; is_multiple_of_3(x) ==> x % 3 == 0;
*/

/*@
requires is_multiple_of_3(x);
ensures x % 3 == 0;
*/
void lemma_multiple_of_3(int x) {
    //@ assert x % 3 == 0;
}

/*@
ensures \forall integer x; is_multiple_of_3(x) ==> x % 3 == 0;
*/
void test_multiple_of_3() {
    /*@
    loop invariant 0 <= i <= 1000;
    loop invariant \forall integer j; 0 <= j < i ==> (is_multiple_of_3(j) ==> j % 3 == 0);
    loop assigns i;
    */
    for (int i = 0; i < 1000; ++i) {
        //@ assert is_multiple_of_3(i) ==> i % 3 == 0;
    }
}

int main() {
    test_multiple_of_3();
    return 0;
}
