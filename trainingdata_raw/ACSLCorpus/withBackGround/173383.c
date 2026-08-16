/*@
predicate requires_f(integer x) = x == 50;

predicate ensures_f{L}(integer x, integer y) = y == x + 1;

lemma ensures_proof:
    \forall integer x, integer y; ensures_f(x, y) ==> y == x + 1;
*/

/*@
requires requires_f(x);
ensures ensures_f(x, \result);
*/
int f(int x);

/*@
requires requires_f(50);
ensures \result == 51;
*/
int func()
{
    // Variable declarations
    int ret;
    
    // Function call
    ret = f(50);
    
    // Verification
    //@ assert ensures_f(50, ret);
    //@ assert ret == 51;
    
    return ret;
}

int main()
{
    return 0;
}
