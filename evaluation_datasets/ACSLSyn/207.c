#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_negative_one(integer n, integer m) = n >= 10 || m >= 10;
    predicate both_small(integer n, integer m) = n < 10 && m < 10;
    logic integer product(integer n, integer m) = n * m;
*/

int func1(int n, int m)
{
    bool is_negative_one_val;
    int result;
    
    is_negative_one_val = n >= 10 || m >= 10;
    
    if (is_negative_one_val)
    {
        //@ assert is_negative_one(n, m);
        return -1;
    }
    
    //@ assert 1 <= n && n < 10;
    //@ assert 1 <= m && m < 10;
    //@ assert 1 <= product(n, m) && product(n, m) < 100;
    
    result = n * m;
    return result;
}

struct Rectangle {
    uint32_t width;
    uint32_t height;
};

/*@ predicate is_square(integer width, integer height) =
      width == height && width > 0;
*/

/*@ logic integer area(integer width, integer height) =
      width * height;
*/

int func2(int a, int b) {
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    return a * b;
}

int process_rectangle_dimensions(int width, int height) {
    int side;
    
    //@ assert is_square(width, height);
    //@ assert width == height;
    //@ assert width > 0 && height > 0;
    
    int validation = func1(width, height);
    //@ assert validation == -1 || validation == product(width, height);
    
    side = func2(width, height);
    //@ assert side == width * height;
    
    //@ assert side == area(width, height);
    //@ assert side > 0;
    
    return side;
}
