/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate in_range(integer x) = 1 <= x <= 100;
    
    logic integer trapezoid_area(integer a, integer b, integer h) = (a + b) * h / 2;
    
    lemma product_bounds:
        \forall integer a, b, h;
        in_range(a) && in_range(b) && in_range(h) ==> 
        1 <= (a + b) * h <= 200 * 100;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(h);
    requires is_even(h);
    ensures \result == trapezoid_area(a, b, h);
    assigns \nothing;
*/
int func(int a, int b, int h) {
    int sum;
    int product;
    int half;
    int result;
    int temp;
    
    sum = a + b;
    
    //@ assert 1 <= (a + b) * h <= 200 * 100;
    
    product = sum * h;
    half = 2;
    result = 0;
    temp = product;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= h <= 100;
        loop invariant h % 2 == 0;
        loop invariant sum == a + b;
        loop invariant product == sum * h;
        loop invariant half == 2;
        loop invariant temp >= 0;
        loop invariant temp + half * result == product;
        loop invariant result >= 0;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= half) {
        temp -= half;
        result += 1;
    }
    
    return result;
}
