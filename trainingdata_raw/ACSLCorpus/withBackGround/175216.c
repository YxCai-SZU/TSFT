#include <stdbool.h>

/*@
    predicate is_square(integer length, integer width) = length == width;

    logic integer perimeter(integer length, integer width) = 2 * (length + width);

    lemma scale_bounds:
        \forall integer length, scale;
        0 <= length && length <= 10000 && 0 <= scale && scale <= 100 ==> length * scale <= 1000000;
*/

typedef struct {
    unsigned int length;
    unsigned int width;
} Rectangle;

/*@
    requires rect.length == rect.width;
    ensures \result == true;
    assigns \nothing;
*/
bool is_square_func(Rectangle rect) {
    //@ assert rect.length == rect.width;
    return true;
}

/*@
    requires rect.length <= 10000;
    requires rect.width <= 10000;
    requires scale <= 100;
    ensures \result.length == rect.length * scale;
    ensures \result.width == rect.width * scale;
    assigns \nothing;
*/
Rectangle scale_rectangle(Rectangle rect, unsigned int scale) {
    //@ assert rect.length * scale <= 1000000;
    //@ assert rect.width * scale <= 1000000;
    
    Rectangle scaled;
    scaled.length = rect.length * scale;
    scaled.width = rect.width * scale;
    
    return scaled;
}
