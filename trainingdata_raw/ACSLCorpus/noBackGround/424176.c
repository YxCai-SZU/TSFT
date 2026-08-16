#include <stdint.h>

/*@ requires ((radius) <= 100);
    ensures ((\result) == 3 * (radius) * (radius));
    assigns \nothing;
*/
uint32_t area_circle(uint32_t radius) {
    //@ assert 0 <= 3 * radius * radius <= 3 * 100 * 100;
    return 3 * radius * radius;
}

/*@ requires ((side) <= 100);
    ensures ((\result) == (side) * (side));
    assigns \nothing;
*/
uint32_t area_square(uint32_t side) {
    //@ assert 0 <= side * side <= 100 * 100;
    return side * side;
}

/*@ requires dimension <= 100;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t calculate_area_circle(uint32_t dimension) {
    uint32_t result;
    result = area_circle(dimension);
    //@ assert result >= 0;
    return result;
}

/*@ requires dimension <= 100;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t calculate_area_square(uint32_t dimension) {
    uint32_t result;
    result = area_square(dimension);
    //@ assert result >= 0;
    return result;
}

int main() {
    uint32_t circle_area;
    uint32_t square_area;
    
    circle_area = calculate_area_circle(10);
    //@ assert circle_area >= 0;
    
    square_area = calculate_area_square(10);
    //@ assert square_area >= 0;
    
    return 0;
}
