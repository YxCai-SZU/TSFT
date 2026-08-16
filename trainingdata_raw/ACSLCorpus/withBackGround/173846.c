/*@
    predicate valid_input(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    logic integer total_kakera(integer a, integer p) = a * 3 + p;

    predicate pies_bounds(integer pies, integer a, integer p) =
        pies >= 0 && pies <= total_kakera(a, p);
*/

/*@
    requires valid_input(a, p);
    ensures pies_bounds(\result, a, p);
*/
int func(int a, int p)
{
    int kakera;
    int pies;
    int count;

    //@ assert valid_input(a, p);
    
    kakera = a * 3 + p;
    pies = 0;
    count = 0;
    
    /*@
        loop invariant 0 <= kakera <= total_kakera(a, p);
        loop invariant 0 <= count <= (total_kakera(a, p) - kakera) / 2;
        loop invariant pies == 0;
        loop invariant valid_input(a, p);
        loop assigns kakera, count;
        loop variant kakera;
    */
    while (kakera >= 2)
    {
        kakera -= 2;
        count += 1;
    }
    
    pies = count;
    
    //@ assert pies_bounds(pies, a, p);
    return pies;
}
