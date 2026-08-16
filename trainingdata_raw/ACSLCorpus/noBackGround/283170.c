#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef enum {
    PLANT_TREE,
    PLANT_FLOWER,
    PLANT_BUSH
} PlantTag;

typedef struct {
    PlantTag tag;
    union {
        struct {
            uint32_t age_years;
            char* species;
        } tree;
        struct {
            char* color;
            uint8_t petals;
        } flower;
        struct {
            char* type_bush;
            uint16_t height_cm;
        } bush;
    } data;
} Plant;

/*@
    assigns \nothing;
*/
void main_func(void) {
    Plant tall_bush;
    
    tall_bush.tag = PLANT_BUSH;
    tall_bush.data.bush.type_bush = "Rose";
    tall_bush.data.bush.height_cm = 150;
    
    //@ assert ((tall_bush.data.bush.height_cm) > 50);
}
