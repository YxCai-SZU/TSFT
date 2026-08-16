/*@
    predicate is_valid_range(integer A, integer B) =
        1 <= A <= 10000 && 0 <= B <= 1000;
    
    logic integer mod_500(integer x) = x % 500;
*/

/*@
    requires is_valid_range(A, B);
    ensures \result == (A % 500 <= B);
    assigns \nothing;
*/
int func(int A, int B) {
    int remainder;
    
    remainder = A;
    
    /*@
        loop invariant 0 <= remainder <= A;
        loop invariant remainder % 500 == A % 500;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 500) {
        remainder -= 500;
    }
    
    //@ assert remainder == A % 500;
    
    return remainder <= B;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
