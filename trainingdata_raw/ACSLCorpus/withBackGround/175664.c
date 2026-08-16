/*@
    predicate is_valid_param(integer p) = 1 <= p && p <= 10;
    logic integer total_sum(integer t0, integer t1, integer t2, integer t3, integer t4,
                           integer t5, integer t6, integer t7, integer t8, integer t9) =
        t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9;
    lemma param_equality: \forall integer a, b; a == b ==> a == b;
*/

/*@
    requires is_valid_param(t0) && is_valid_param(t1) && is_valid_param(t2) && 
             is_valid_param(t3) && is_valid_param(t4) && is_valid_param(t5) && 
             is_valid_param(t6) && is_valid_param(t7) && is_valid_param(t8) && 
             is_valid_param(t9);
    ensures \result == total_sum(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9);
    assigns \nothing;
*/
int func(int t0, int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9)
{
    int sum;
    //@ assert t0 >= 1 && t0 <= 10;
    //@ assert t1 >= 1 && t1 <= 10;
    //@ assert t2 >= 1 && t2 <= 10;
    //@ assert t3 >= 1 && t3 <= 10;
    //@ assert t4 >= 1 && t4 <= 10;
    //@ assert t5 >= 1 && t5 <= 10;
    //@ assert t6 >= 1 && t6 <= 10;
    //@ assert t7 >= 1 && t7 <= 10;
    //@ assert t8 >= 1 && t8 <= 10;
    //@ assert t9 >= 1 && t9 <= 10;
    
    sum = t0 + t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9;
    
    //@ assert sum >= 10 * 1;
    //@ assert sum <= 10 * 10;
    
    return sum;
}

int main()
{
    return 0;
}
