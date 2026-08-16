/*@
    predicate positive(integer x) = x > 0;
    predicate product_safe(integer b, integer h) = b * h < 10000;
    
    logic integer triangle_area_spec(integer base, integer height) =
        (base * height) / 2;
*/

/*@
    requires positive(base) && positive(height) && product_safe(base, height);
    ensures \result == triangle_area_spec(base, height);
    assigns \nothing;
*/
unsigned int triangle_area(unsigned int base, unsigned int height)
{
    unsigned int product;
    unsigned int area;
    
    //@ assert product_safe(base, height);
    
    product = base * height;
    area = product / 2;
    
    //@ assert area == triangle_area_spec(base, height);
    return area;
}

int main(void)
{
    return 0;
}
