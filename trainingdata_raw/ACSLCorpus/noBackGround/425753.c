/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result <= a * 3 + p;
    ensures \result == (a * 3 + p) / 2;
*/
unsigned int func(unsigned int a, unsigned int p)
{
    unsigned int kakera;
    unsigned int pies;

    kakera = a * 3 + p;
    //@ assert kakera <= a * 3 + p;
    pies = kakera / 2;
    return pies;
}
