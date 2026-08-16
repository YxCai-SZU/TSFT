#include <stdbool.h>
#include <stdint.h>

/* First function: checks if a pair (a,b) within [0,n-1] satisfies a specific property */
/*@
    predicate diff_eq_one(integer a, integer b) = (b - a == 1);
    predicate diff_not_one_and_valid(integer n, integer a, integer b) = 
        (b - a != 1) && (a != 0) && (b != n - 1);
    predicate expected_result(integer n, integer a, integer b) =
        diff_eq_one(a, b) || diff_not_one_and_valid(n, a, b);
*/

bool func_pair(int n, int a, int b)
{
    //@ assert 0 <= a < b < n;
    int diff = b - a;
    //@ assert diff == b - a;
    bool result;
    
    if (diff == 1 || (diff != 1 && a != 0 && b != n - 1)) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (b - a == 1 || (b - a != 1 && a != 0 && b != n - 1));
    
    return result;
}

/* Second function: checks if a plant is a tall bush */
/*@
    predicate is_tall_bush(integer height_cm) = height_cm > 50;
    
    lemma bush_height_positive: \forall integer h; is_tall_bush(h) ==> h > 0;
*/

int func_identity(int x)
{
    //@ assert x >= 1 && x <= 10;
    return x;
}

enum Plant_Tag { TREE, FLOWER, BUSH };

struct Plant {
    enum Plant_Tag tag;
    union {
        struct { uint32_t age_years; } tree;
        struct { char* color; } flower;
        struct { uint16_t height_cm; } bush;
    } data;
};

bool check_plant_height(struct Plant* plant)
{
    //@ assert plant->tag == BUSH;
    return plant->data.bush.height_cm > 50;
}

bool func_tall_bush(struct Plant* plant)
{
    //@ assert plant->tag == BUSH;
    bool result = check_plant_height(plant);
    //@ assert result == (plant->data.bush.height_cm > 50);
    return result;
}

/* Synthesized function: Garden Path Planning - checks if a valid bush pair exists in a garden row */
/* Scenario: In a garden with n plants arranged in a line (indices 0..n-1), we need to select 
   two bush plants at positions a and b (a<b) that are either adjacent or both non-edge, 
   and both must be tall bushes (height > 50cm). This represents a real-world constraint 
   for creating a visually balanced garden path. */

bool garden_path_planning(int n, int a, int b, struct Plant plants[])
{
    bool position_valid = func_pair(n, a, b);
    
    //@ assert plants[a].tag == BUSH;
    bool plant_a_tall = check_plant_height(&plants[a]);
    
    //@ assert plants[b].tag == BUSH;
    bool plant_b_tall = check_plant_height(&plants[b]);
    
    bool result = position_valid && plant_a_tall && plant_b_tall;
    
    //@ assert result == ((b - a == 1 || (b - a != 1 && a != 0 && b != n - 1)) && plants[a].data.bush.height_cm > 50 && plants[b].data.bush.height_cm > 50);
    
    return result;
}
