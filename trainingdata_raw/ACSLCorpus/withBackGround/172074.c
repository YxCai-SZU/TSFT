/*@
    predicate is_even(integer x) =
        x < 2 ? \true : is_even(x - 2);
    
    lemma is_even_increases:
        \forall integer x; is_even(x) <==> is_even(x);
*/

int main() {
    //@ assert \true;
    return 0;
}
