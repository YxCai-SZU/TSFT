/*@
requires x > 5;
ensures \result > 0;
assigns \nothing;
*/
int proof_subtraction(int x)
{
    //@ assert x - 5 > 0;
    return x - 5;
}

/*@
requires x > 0;
ensures \result > 0;
assigns \nothing;
*/
int proof_multiplication(int x)
{
    //@ assert x * 5 > 0;
    return x * 5;
}

/*@
requires x > 0;
ensures \result <= x;
assigns \nothing;
*/
int proof_division(int x)
{
    //@ assert x / 5 <= x;
    return x / 5;
}

/*@
requires x > 5;
ensures *r1 > 0 && *r2 > 0 && *r3 <= x;
assigns *r1, *r2, *r3;
*/
void combined_proof(int x, int* r1, int* r2, int* r3)
{
    //@ assert x - 5 > 0;
    *r1 = x - 5;
    
    //@ assert x * 5 > 0;
    *r2 = x * 5;
    
    //@ assert x / 5 <= x;
    *r3 = x / 5;
}

int main()
{
    return 0;
}
