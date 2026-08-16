/*@
    predicate valid_radius(integer r) = 1 <= r && r <= 100;
    
    logic integer two_r_pi(integer r) = 2 * r * 3;
    
    lemma circumference_non_negative:
        \forall integer r; valid_radius(r) ==> two_r_pi(r) >= 0;
*/

/*@
    requires valid_radius(r);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int circumference = 0;
    int temp = 2 * r * pi;
    int count = 0;
    
    /*@
        loop invariant 0 <= temp;
        loop invariant temp <= 2 * r * pi;
        loop invariant count >= 0;
        loop invariant count <= 2 * r * pi / 1000;
        loop invariant 1 <= r <= 100;
        loop invariant temp == 2 * r * pi - 1000 * count;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        temp -= 1000;
        count += 1;
    }
    
    circumference = count;
    
    //@ assert circumference >= 0;
    
    return circumference;
}
