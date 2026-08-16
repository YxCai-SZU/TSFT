#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 9) && (1 <= (g) && (g) <= 9) && (1 <= (b) && (b) <= 9);
    ensures \result == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
*/
bool func(int r, int g, int b) {
    int rgb;
    int temp_rgb;
    
    rgb = r * 100 + g * 10 + b;
    temp_rgb = rgb;
    
    /*@
        loop invariant 1 <= r && r <= 9;
        loop invariant 1 <= g && g <= 9;
        loop invariant 1 <= b && b <= 9;
        loop invariant 0 <= temp_rgb;
        loop invariant temp_rgb <= rgb;
        loop invariant rgb % 4 == temp_rgb % 4;
        loop assigns temp_rgb;
    */
    while (temp_rgb >= 4) {
        temp_rgb -= 4;
    }
    
    //@ assert rgb % 4 == temp_rgb;
    
    if (temp_rgb == 0) {
        return true;
    } else {
        return false;
    }
}
