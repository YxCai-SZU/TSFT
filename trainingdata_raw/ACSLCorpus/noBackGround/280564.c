/*@
requires x <= y;
ensures ((x) >= 0) ==> ((y) >= 0);
assigns \nothing;
*/
void lemma_is_natural_concrete(int x, int y)
{
    //@ assert x <= y;
}

/*@
ensures \forall integer x, y;
    x <= y && ((x) >= 0) ==> ((y) >= 0);
assigns \nothing;
*/
void establish_forall_is_natural()
{
    int i;
    int x;
    int y;
    
    /*@
    loop invariant 0 <= i <= 100;
    loop invariant \forall integer x, y;
        0 <= x < i && x <= y && ((x) >= 0) ==> ((y) >= 0);
    loop assigns i, x, y;
    */
    for (i = 0; i < 100; i++)
    {
        x = i;
        y = i + 1;
        
        //@ assert x <= y;
        lemma_is_natural_concrete(x, y);
    }
}

/*@
assigns \nothing;
*/
int main()
{
    establish_forall_is_natural();
    return 0;
}
