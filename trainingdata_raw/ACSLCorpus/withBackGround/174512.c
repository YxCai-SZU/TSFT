#include <stdint.h>

/*@
    predicate valid_dimensions(integer w, integer h) =
        w > 0 && h > 0 && w <= 100 && h <= 100;

    logic integer rectangle_area(integer w, integer h) = w * h;

    logic integer rectangle_perimeter(integer w, integer h) = 2 * (w + h);

    lemma area_bound:
        \forall integer w, h;
            valid_dimensions(w, h) ==> rectangle_area(w, h) <= 10000;
*/

/*@
    requires valid_dimensions(width, height);
    ensures \result == rectangle_area(width, height);
    assigns \nothing;
*/
uint32_t area_rectangle(uint32_t width, uint32_t height)
{
    //@ assert valid_dimensions(width, height);
    //@ assert rectangle_area(width, height) <= 10000;
    return width * height;
}

/*@
    requires valid_dimensions(width, height);
    ensures \result == rectangle_perimeter(width, height);
    assigns \nothing;
*/
uint32_t perimeter_rectangle(uint32_t width, uint32_t height)
{
    //@ assert valid_dimensions(width, height);
    return 2 * (width + height);
}

/*@
    requires valid_dimensions(width, height);
    assigns \nothing;
*/
void rectangle_prop(uint32_t width, uint32_t height)
{
    uint32_t area;
    uint32_t perimeter;

    //@ assert valid_dimensions(width, height);
    area = area_rectangle(width, height);
    //@ assert area == rectangle_area(width, height);
    perimeter = perimeter_rectangle(width, height);
    //@ assert perimeter == rectangle_perimeter(width, height);
}

int main()
{
    return 0;
}
