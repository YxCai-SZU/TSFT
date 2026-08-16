/*@
    predicate x_is_five(integer x) = x == 5;
    predicate y_is_three(integer y) = y == 3;
    lemma my_proof: \forall integer x, y; x_is_five(x) && y_is_three(y) ==> x_is_five(x) && y_is_three(y);
*/

int main() {
    int x;
    int y;
    
    //@ ghost x = 5;
    //@ ghost y = 3;
    
    //@ assert x_is_five(x);
    //@ assert y_is_three(y);
    
    return 0;
}
