/*@
    requires \true;
    ensures \forall integer x, y; ((x) <= (y)) ==> (((x) <= (y)) ? ((x) + (y)) : ((x) - (y))) == x + y;
*/
void establish_forall()
{
    /*@
        loop invariant 0 <= i <= 100;
        loop invariant \forall integer x, y; (0 <= x < i && ((x) <= (y))) ==> (((x) <= (y)) ? ((x) + (y)) : ((x) - (y))) == x + y;
        loop assigns i;
    */
    for (int i = 0; i < 100; ++i)
    {
        /*@
            loop invariant 0 <= j <= 100;
            loop invariant \forall integer y; (0 <= y < j && ((i) <= (y))) ==> (((i) <= (y)) ? ((i) + (y)) : ((i) - (y))) == i + y;
            loop assigns j;
        */
        for (int j = 0; j < 100; ++j)
        {
            //@ assert ((i) <= (j)) ==> (((i) <= (j)) ? ((i) + (j)) : ((i) - (j))) == i + j;
        }
    }
}

int main()
{
    establish_forall();
    return 0;
}
