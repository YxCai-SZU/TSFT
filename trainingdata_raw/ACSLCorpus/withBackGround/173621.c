/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10000;

    lemma mult_no_overflow:
        \forall integer a, integer b;
        is_valid_range(a) && is_valid_range(b) ==> a * b <= 2147483647;
*/

/*@
    requires \valid(res);
    requires is_valid_range(A) && is_valid_range(B);
    requires is_valid_range(C) && is_valid_range(D);
    assigns *res;
    ensures *res == A * B || *res == C * D;
    ensures *res >= A * B && *res >= C * D;
*/
void func(int A, int B, int C, int D, int *res) {
    int s1;
    int s2;
    int local_res;

    //@ assert is_valid_range(A) && is_valid_range(B);
    //@ assert is_valid_range(C) && is_valid_range(D);
    //@ assert A * B <= 2147483647;
    
    s1 = A * B;
    s2 = C * D;

    if (s1 > s2) {
        local_res = s1;
    } else {
        local_res = s2;
    }

    //@ assert local_res == A * B || local_res == C * D;
    //@ assert local_res >= A * B && local_res >= C * D;

    *res = local_res;
}
