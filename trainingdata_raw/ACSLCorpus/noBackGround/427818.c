/*@
requires v1 < v2;
requires v2 < v3;
ensures v1 < v3;
*/
void example(int v1, int v2, int v3)
{
    //@ assert v1 < v2;
    //@ assert v2 < v3;
    //@ assert v1 < v3;
}
