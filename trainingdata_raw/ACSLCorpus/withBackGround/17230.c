/*@
predicate valid_input(integer a, integer b) =
    (a == 1 && b == 0) || (a == 0 && b == 1) || (a == 0 && b == 0) || (a == 1 && b == 1);

predicate postcondition(integer a, integer b, integer res) =
    (a == 1 && b == 0 ==> res == 1) &&
    (a == 0 && b == 1 ==> res == 0) &&
    (a == 0 && b == 0 ==> res == 0) &&
    (a == 1 && b == 1 ==> res == 0);

lemma proof_lemma:
    \forall integer a, b, res;
    valid_input(a, b) ==>
    ((a == 1 && b == 0 && res == 1) ||
     (a == 0 && b == 1 && res == 0) ||
     (a == 0 && b == 0 && res == 0) ||
     (a == 1 && b == 1 && res == 0)) ==>
    postcondition(a, b, res);
*/

/*@
requires valid_input(a, b);
ensures postcondition(a, b, \result);
assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    
    //@ assert valid_input(a, b);
    
    if ((a == 1) && (b == 0)) {
        res = 1;
    } else {
        res = 0;
    }
    
    //@ assert (a == 1 && b == 0 && res == 1) || (a == 0 && b == 1 && res == 0) || (a == 0 && b == 0 && res == 0) || (a == 1 && b == 1 && res == 0);
    
    //@ assert postcondition(a, b, res);
    
    return res;
}
