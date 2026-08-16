/*@
predicate negation(integer x, integer r) = r == -x;

lemma negation_nonlinear_arith:
    \forall integer x, y;
        x == y ==> negation(x, -x) && negation(y, -y) && -x == -y;
*/

/*@
requires \true;
assigns \nothing;
ensures \result == -10;
*/
int use_broadcast_negation() {
    int x;
    int y;
    int result_x;
    int result_y;
    
    x = 10;
    y = 10;
    
    //@ assert x == y;
    //@ assert negation(x, -x);
    //@ assert negation(y, -y);
    //@ assert -x == -y;
    
    result_x = -x;
    result_y = -y;
    
    //@ assert result_x == result_y;
    return result_x;
}

int main() {
    int res;
    res = use_broadcast_negation();
    return 0;
}
