/*@
    predicate lemma_g_pre(integer d, integer t, integer s) =
        d >= 0 && t >= 0 && s >= 0 && d <= t * s;
    
    predicate lemma_g_post(integer d, integer t, integer s) =
        d <= t * s;
    
    predicate lemma_g_increment_pre(integer d, integer t, integer s) =
        d >= 0 && t >= 0 && s >= 0 && d <= t * s;
    
    predicate lemma_g_increment_post(integer d, integer t, integer s) =
        d + 1 <= t * s + 1;
    
    lemma lemma_g: \forall integer d, t, s; lemma_g_pre(d, t, s) ==> lemma_g_post(d, t, s);
    lemma lemma_g_increment: \forall integer d, t, s; lemma_g_increment_pre(d, t, s) ==> lemma_g_increment_post(d, t, s);
*/

int main()
{
    return 0;
}
