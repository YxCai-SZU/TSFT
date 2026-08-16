/* ============================================================
   Scenario: Jewelry Box Volume Calculation
   Description: We have a necklace factory that produces heavy necklaces.
   For each necklace, we compute its "box volume" as the cube of its
   weight (since the necklace is stored in a cubic box whose side length
   equals the weight). The main function checks whether the resulting
   volume is even (i.e., divisible by 2). This combines:
     - func: checks if a product is even
     - create_necklace + accessory_size: constructs a necklace and extracts its weight
     - compute_volume_cube: computes side^3
   ============================================================ */

#include <stdbool.h>

/* ---------- First snippet: func (parity check) ---------- */
/*@
    predicate is_within_bounds(integer a, integer b) =
        1 <= a && a <= 10000 && 1 <= b && b <= 10000;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b;
        is_within_bounds(a, b) ==> safe_product(a, b) <= 100000000;
*/

int func(int a, int b) {
    int result;
    int c;

    //@ assert is_within_bounds(a, b);
    //@ assert safe_product(a, b) <= 100000000;

    c = a * b;
    result = (c % 2 == 0);
    return result;
}

/* ---------- Second snippet: Accessory types ---------- */
enum Accessory {
    Necklace,
    Bracelet,
    Earring
};

struct Accessory_data {
    enum Accessory tag;
    union {
        unsigned int weight;
        unsigned int circumference;
        unsigned int length;
    } value;
};

/*@
    predicate is_heavy_necklace(struct Accessory_data a) =
        a.tag == Necklace && a.value.weight > 15;

    logic integer accessory_size(struct Accessory_data a) =
        a.tag == Necklace ? a.value.weight :
        a.tag == Bracelet ? a.value.circumference :
        a.value.length;

    predicate size_threshold(struct Accessory_data a, integer threshold) =
        a.tag == Necklace ? a.value.weight > threshold :
        a.tag == Bracelet ? a.value.circumference > threshold :
        a.value.length > threshold;
*/

void test_accessory(void) {
    struct Accessory_data gold_bracelet;
    gold_bracelet.tag = Bracelet;
    gold_bracelet.value.circumference = 20;
    
    //@ assert accessory_size(gold_bracelet) == 20;
}

struct Accessory_data create_necklace(unsigned int weight) {
    struct Accessory_data necklace;
    necklace.tag = Necklace;
    necklace.value.weight = weight;
    return necklace;
}

/* ---------- Third snippet: cube volume ---------- */
/*@
    predicate side_nonnegative(integer side) = side >= 0;

    logic integer volume_cube(integer side) =
        side < 0 ? 0 :
        side == 0 ? 0 :
        side * side * side;

    lemma volume_cube_nonnegative:
        \forall integer side;
            side_nonnegative(side) ==> volume_cube(side) >= 0;
*/

int compute_volume_cube(int side) {
    int result;
    //@ assert side_nonnegative(side);
    
    if (side < 0) {
        result = 0;
    } else if (side == 0) {
        result = 0;
    } else {
        //@ assert side > 0;
        //@ assert side * side * side >= 0;
        result = side * side * side;
    }
    
    //@ assert result >= 0;
    //@ assert result == volume_cube(side);
    return result;
}

/* ---------- Synthesized main function ---------- */

int check_necklace_box_parity(unsigned int weight) {
    int parity;
    int vol;
    struct Accessory_data necklace;

    necklace = create_necklace(weight);
    //@ assert necklace.tag == Necklace;
    //@ assert necklace.value.weight == weight;

    //@ assert accessory_size(necklace) == (int)weight;
    //@ assert (int)weight >= 0;   // weight is unsigned, but fits in int due to precondition

    vol = compute_volume_cube((int)weight);
    //@ assert vol == volume_cube((int)weight);
    //@ assert vol >= 0;

    //@ assert 1 <= vol && vol <= 10000;
    parity = func(vol, 1);
    //@ assert parity == ((vol * 1) % 2 == 0);
    //@ assert parity == (vol % 2 == 0);

    //@ assert parity == (volume_cube((int)weight) % 2 == 0);
    return parity;
}

int main(void) {
    int result = check_necklace_box_parity(3);  // 3^3=27, odd -> 0
    return result;
}
