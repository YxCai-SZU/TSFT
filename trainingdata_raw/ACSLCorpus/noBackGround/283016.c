/*@
    requires 1 <= N <= 9;
    ensures \result == N * N * N;
    assigns \nothing;
*/
unsigned int func(unsigned int N)
{
    unsigned int result;
    
    //@ assert 1 <= N && N <= 9;
    //@ assert N * N <= 81;
    //@ assert N * N * N <= 729;
    
    result = N * N * N;
    return result;
}

int main(void)
{
    return 0;
}
