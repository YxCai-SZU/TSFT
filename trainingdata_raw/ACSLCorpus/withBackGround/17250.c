/*@
    predicate valid_range(integer x) = 1 <= x && x <= 20;

    lemma division_bound: \forall integer T, A; 
        valid_range(T) && valid_range(A) ==> T / A <= 20;
    lemma multiplication_bound: \forall integer T, A, B; 
        valid_range(T) && valid_range(A) && valid_range(B) ==> T / A * B <= 400;
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(T);
    ensures \result == T / A * B;
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int B, unsigned int T)
{
    unsigned int ans;
    
    //@ assert A >= 1 && A <= 20;
    //@ assert B >= 1 && B <= 20;
    //@ assert T >= 1 && T <= 20;
    //@ assert T / A <= 20;
    //@ assert T / A * B <= 400;
    
    ans = T / A * B;
    
    return ans;
}

int main()
{
    return 0;
}
