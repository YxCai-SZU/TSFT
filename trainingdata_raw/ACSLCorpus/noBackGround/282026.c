/*@
requires x >= 0;
ensures \true;
*/
void is_positive_proof(int x)
{
    //@ assert x >= 0;
    
    if (x > 0) {
        //@ assert x >= 1;
    }
}

int main()
{
    return 0;
}
