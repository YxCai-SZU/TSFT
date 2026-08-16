/*@
    predicate is_bool(integer x) = 0 <= x <= 1;

    lemma sum_bound:
        \forall integer a, b, c, d;
            is_bool(a) && is_bool(b) && is_bool(c) && is_bool(d) ==>
            a + b + c + d <= 4;
*/

/*@
    requires 0 <= a <= 1;
    requires 0 <= b <= 1;
    requires 0 <= c <= 1;
    requires 0 <= d <= 1;
    ensures \result <= 4;
*/
int func(int a, int b, int c, int d) {
    int sum;

    //@ assert 0 <= a <= 1;
    sum = a;
    
    //@ assert 0 <= b <= 1;
    sum = sum + b;
    
    //@ assert 0 <= c <= 1;
    sum = sum + c;
    
    //@ assert 0 <= d <= 1;
    sum = sum + d;
    
    //@ assert sum <= 4;
    return sum;
}

int main() {
    return 0;
}
