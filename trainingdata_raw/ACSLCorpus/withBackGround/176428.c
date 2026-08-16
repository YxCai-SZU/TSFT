/*@
predicate is_leq(integer a, integer b, integer c, integer d) =
    a <= b && b <= c && c <= d;

lemma increasing_chain:
    \forall integer a, b, c, d;
    a <= b && b <= c && c <= d ==> is_leq(a, b, c, d);
*/

/*@
requires \true;
ensures is_leq(1+1, 2+2, 4+4, 8+8);
*/
void example_is_increasingly_complex_f(void) {
    int total;
    int intermediate;
    int temp;
    
    total = 1 + 1;
    //@ assert total == 2;
    
    intermediate = 2 + 2;
    //@ assert intermediate == 4;
    
    temp = 4 + 4;
    //@ assert temp == 8;
    
    total = temp;
    //@ assert total == 8;
    
    intermediate = 8 + 8;
    //@ assert intermediate == 16;
    
    //@ assert is_leq(1+1, 2+2, 4+4, 8+8);
}

int main(void) {
    example_is_increasingly_complex_f();
    return 0;
}
