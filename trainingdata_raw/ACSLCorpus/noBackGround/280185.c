/*@
    requires (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    requires (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    requires 0 <= k && k <= 23 * 60 + 59;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == 60 * (h2 - h1) + m2 - m1 - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    //@ assert h2 - h1 <= 23;
    //@ assert 60 * (h2 - h1) + m2 - m1 >= 0;
    //@ assert 60 * (h2 - h1) + m2 - m1 <= 23 * 60 + 59;
    
    return 60 * (h2 - h1) + m2 - m1 - k;
}
