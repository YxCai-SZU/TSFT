/*@
    predicate nonnegative(integer x) = x >= 0;

    lemma calc_example_4:
        \forall integer x, y;
            nonnegative(x) && nonnegative(y) ==>
            x * 2 + y * 3 >= x + y;
*/

/*@
    requires x >= 0 && y >= 0;
    ensures \result >= x + y;
*/
int calc_example_4_impl(int x, int y) {
    int result;

    //@ assert x * 2 >= x;
    //@ assert y * 3 >= y;
    
    result = x * 2 + y * 3;
    
    //@ assert result >= x + y;
    return result;
}

int main() {
    return 0;
}
