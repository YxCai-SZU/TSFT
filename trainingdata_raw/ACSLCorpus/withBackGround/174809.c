/*@
    predicate valid_dimensions(integer w, integer h, integer d) =
        w > 0 && h > 0 && d > 0 &&
        w <= 10 && h <= 10 && d <= 10;
    
    logic integer volume(integer w, integer h, integer d) = w * h * d;
    
    lemma product_bound1: \forall integer w, h; 0 < w <= 10 && 0 < h <= 10 ==> w * h <= 100;
    lemma product_bound2: \forall integer w, h, d; 0 < w <= 10 && 0 < h <= 10 && 0 < d <= 10 ==> w * h * d <= 1000;
*/

/*@
    requires valid_dimensions(width, height, depth);
    ensures \result == volume(width, height, depth);
    assigns \nothing;
*/
unsigned int volume_rectangular_prism(unsigned int width, unsigned int height, unsigned int depth)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    // Precondition verification
    //@ assert width > 0 && height > 0 && depth > 0;
    //@ assert width <= 10 && height <= 10 && depth <= 10;
    
    // Overflow prevention
    //@ assert width * height <= 100;
    //@ assert width * height * depth <= 1000;
    
    result = width * height * depth;
    
    // Postcondition verification
    //@ assert result == width * height * depth;
    
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
