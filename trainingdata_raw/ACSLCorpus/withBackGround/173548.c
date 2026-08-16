/*@
predicate positive(integer v) = v > 0;
predicate ordered(integer x, integer y) = x <= y;

lemma func_lemma:
    \forall integer x, y;
    positive(x) && positive(y) && ordered(x, y) ==> x + y <= 2 * y;

lemma func1_lemma:
    \forall integer x, y;
    positive(x) && positive(y) && ordered(x, y) ==> x + y <= 2 * y;

lemma func2_lemma:
    \forall integer x, y;
    positive(x) && positive(y) && ordered(x, y) ==> x + y <= 2 * y;

lemma func3_lemma:
    \forall integer x, y;
    positive(x) && positive(y) && ordered(x, y) ==> x + y <= 2 * y;
*/

/*@
requires x > 0 && y > 0 && x <= y;
ensures \result <= 2 * y;
*/
int func(int x, int y) {
    int result;
    result = x + y;
    
    //@ assert positive(x);
    //@ assert positive(y);
    //@ assert ordered(x, y);
    //@ assert result <= 2 * y;
    
    return result;
}

/*@
requires x > 0 && y > 0 && x <= y;
ensures \result <= 2 * y;
*/
int func1(int x, int y) {
    int result;
    result = x + y;
    
    //@ assert positive(x);
    //@ assert positive(y);
    //@ assert ordered(x, y);
    //@ assert result <= 2 * y;
    
    return result;
}

/*@
requires x > 0 && y > 0 && x <= y;
ensures \result <= 2 * y;
*/
int func2(int x, int y) {
    int result;
    result = x + y;
    
    //@ assert positive(x);
    //@ assert positive(y);
    //@ assert ordered(x, y);
    //@ assert result <= 2 * y;
    
    return result;
}

/*@
requires x > 0 && y > 0 && x <= y;
ensures \result <= 2 * y;
*/
int func3(int x, int y) {
    int result;
    result = x + y;
    
    //@ assert positive(x);
    //@ assert positive(y);
    //@ assert ordered(x, y);
    //@ assert result <= 2 * y;
    
    return result;
}

int main() {
    return 0;
}
