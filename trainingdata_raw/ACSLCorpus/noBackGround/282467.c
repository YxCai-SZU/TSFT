/*@
    requires x >= y;
    ensures \result >= (3 * (y) - 5);
    assigns \nothing;
*/
int lemma_v_greater_than_or_equal(int x, int y)
{
    //@ assert (3 * (x) - 5) >= (3 * (y) - 5);
    return 3 * x - 5;
}

/*@
    ensures \forall integer x, y; x >= y ==> (3 * (x) - 5) >= (3 * (y) - 5);
    assigns \nothing;
*/
void establish_forall()
{
    //@ assert \forall integer x, y; x >= y ==> (3 * (x) - 5) >= (3 * (y) - 5);
}

int main()
{
    int x;
    int y;
    
    establish_forall();
    return 0;
}
