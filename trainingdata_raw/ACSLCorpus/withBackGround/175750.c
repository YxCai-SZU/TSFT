/*@
    predicate non_negative(integer x) = x >= 0;
    
    lemma x_plus_1_lemma: 
        \forall integer x; non_negative(x) ==> x + 1 == x + 1;
*/

/*@
    requires x >= 0;
    ensures \result == x + 1;
    assigns \nothing;
*/
int add_one(int x) {
    //@ assert x >= 0;
    
    int result = x + 1;
    
    //@ assert result == x + 1;
    return result;
}

int main() {
    return 0;
}
