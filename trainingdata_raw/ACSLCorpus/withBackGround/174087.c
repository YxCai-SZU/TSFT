#include <limits.h>

/*@
    logic integer volume_rectangular_prism(integer length, integer width, integer height) =
        length <= 0 ? 0 :
        width <= 0 ? 0 :
        height <= 0 ? 0 :
        length * width * height;
*/

/*@
    lemma volume_rectangular_prism_increases:
        \forall integer length, width, height;
        0 <= length <= INT_MAX &&
        0 <= width <= INT_MAX &&
        0 <= height <= INT_MAX ==>
        volume_rectangular_prism(length, width, height) >= 0 &&
        volume_rectangular_prism(length, width, height) <= length * width * height;
*/

int main() {
    return 0;
}
