#include <limits.h>

/*@ requires ((length) > 0) && ((width) > 0) && ((height) > 0);
    requires ((length) > 0 && (width) > 0 && (height) > 0 && 
      (length) * (width) * (height) <= (integer)INT_MAX);
    ensures \result == length * width * height;
    assigns \nothing;
*/
int volume_rectangular_prism(int length, int width, int height) {
    int base_area;
    int result;

    //@ assert length * width <= INT_MAX;
    base_area = length * width;
    
    //@ assert base_area * height <= INT_MAX;
    result = base_area * height;
    
    return result;
}
