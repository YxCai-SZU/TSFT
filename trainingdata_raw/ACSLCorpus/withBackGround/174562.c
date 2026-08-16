/*@
predicate is_nonnegative(integer x) = x >= 0;

lemma square_is_nonnegative:
    \forall integer x; x >= 0 || x <= 0 ==> x * x >= 0;
*/

/*@
requires x >= 0 || x <= 0;
ensures \result >= 0;
assigns \nothing;
*/
int square(int x) {
    int result;
    
    //@ assert x >= 0 || x <= 0;
    result = x * x;
    //@ assert result >= 0;
    
    return result;
}

int main() {
    return 0;
}
