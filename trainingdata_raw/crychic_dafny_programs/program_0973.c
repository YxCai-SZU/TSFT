// Generated C + ACSL

typedef enum {
    Surface = 0,
    Building = 1,
    LowVegetation = 2,
    Tree = 3,
    Car = 4,
    Background = 5
} ClassType;

#define Color(r, g, b) (((r) << 16) | ((g) << 8) | (b))

/*@
    requires c == 0xFFFFFF || c == 0x0000FF || c == 0x00FFFF ||
             c == 0x00FF00 || c == 0xFFFF00 || c == 0xFF0000;
    assigns \nothing;
    ensures (c == 0xFFFFFF ==> \result == 0) &&
            (c == 0x0000FF ==> \result == 1) &&
            (c == 0x00FFFF ==> \result == 2) &&
            (c == 0x00FF00 ==> \result == 3) &&
            (c == 0xFFFF00 ==> \result == 4) &&
            (c == 0xFF0000 ==> \result == 5);
    ensures \result >= 0 && \result <= 5;
*/
int ColorToClass(int c)
{
  return ((c == Color(255, 255, 255))) ? (Surface) : (((c == Color(0, 0, 255))) ? (Building) : (((c == Color(0, 255, 255))) ? (LowVegetation) : (((c == Color(0, 255, 0))) ? (Tree) : (((c == Color(255, 255, 0))) ? (Car) : (Background)))));
}

// skipped function ExtractPatches due to unsupported type