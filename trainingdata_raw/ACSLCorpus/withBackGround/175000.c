/*@
    predicate is_even(integer x) = x % 2 == 0;
    
    lemma lemma_is_even: \forall integer x; 
        is_even(x) ==> x % 2 == 0 && 
        !is_even(x) ==> x % 2 != 0;
*/

/*@
    requires \true;
    ensures \true;
*/
void test() {
    //@ assert is_even(100);
    //@ assert !is_even(3);
}

/*@
    requires \true;
    ensures \true;
*/
void test2() {
    //@ assert is_even(1000);
    //@ assert !is_even(7);
}

/*@
    requires \true;
    ensures \true;
*/
void test3() {
    //@ assert is_even(10000);
    //@ assert !is_even(11);
}

/*@
    requires \true;
    ensures \true;
*/
void test4() {
    //@ assert is_even(100000);
    //@ assert !is_even(13);
}

int main() {
    return 0;
}
