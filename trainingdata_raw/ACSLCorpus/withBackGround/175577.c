/*@
predicate nonnegative(integer x) = x >= 0;

lemma sum_max_property:
    \forall integer a, integer b;
    nonnegative(a) && nonnegative(b) ==>
    a + b <= 2 * (a + b) / 2 &&
    a <= a + b &&
    b <= a + b;
*/

/*@
    requires a >= 0 && b >= 0;
    ensures \result == a + b;
    ensures \result <= 2 * \result / 2;
    ensures a <= \result;
    ensures b <= \result;
*/
int sum_and_max(int a, int b) {
    int sum;
    
    //@ assert a >= 0;
    //@ assert b >= 0;
    
    sum = a + b;
    
    //@ assert a <= sum;
    //@ assert b <= sum;
    //@ assert sum <= 2 * sum / 2;
    
    return sum;
}

int main() {
    int x = 5;
    int y = 3;
    int result;
    
    //@ assert x >= 0;
    //@ assert y >= 0;
    
    result = sum_and_max(x, y);
    
    return 0;
}
