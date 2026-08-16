/*@
    predicate non_negative(integer a) = 0 <= a;
    predicate within_range(integer a, integer b) = a <= b && b <= 10;
    predicate square_inequality(integer a, integer b) = a * a <= b * b;
    
    lemma func_lemma:
        \forall integer a, b;
            non_negative(a) && within_range(a, b) ==> square_inequality(a, b);
*/

/*@
    requires 0 <= a;
    requires a <= b && b <= 10;
    ensures \result == 0;
    assigns \nothing;
*/
int func(int a, int b) {
    //@ assert 0 <= a && a <= b && b <= 10;
    //@ assert a * a <= b * b;
    
    return 0;
}

int main() {
    return 0;
}
