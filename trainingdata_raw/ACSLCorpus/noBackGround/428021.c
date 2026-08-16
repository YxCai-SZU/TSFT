/*@
    requires \valid(a) && \valid(b) && \valid(c);
    requires *a > 0 && *b > 0 && *c > 0;
    requires *a <= 10 && *b <= 10 && *c <= 10;
    ensures *a * *b * *c <= 1000;
    assigns \nothing;
*/
void nontrivial_proof(int* a, int* b, int* c)
{
    int local_a;
    int local_b;
    int local_c;
    
    local_a = *a;
    local_b = *b;
    local_c = *c;
    
    //@ assert ((local_a) > 0);
    //@ assert ((local_b) > 0);
    //@ assert ((local_c) > 0);
    
    //@ assert (1 <= (local_a) && (local_a) <= 10);
    //@ assert (1 <= (local_b) && (local_b) <= 10);
    //@ assert (1 <= (local_c) && (local_c) <= 10);
    
    //@ assert local_a * local_b <= 100;
    //@ assert local_a * local_b * local_c <= 1000;
}

int main()
{
    return 0;
}
