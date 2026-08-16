#include <stdbool.h>

typedef enum {
    House,
    Apartment,
    Villa
} LocationTag;

typedef struct {
    unsigned char rooms;
    bool garden;
} HouseData;

typedef struct {
    unsigned char floor;
    bool balcony;
} ApartmentData;

typedef struct {
    unsigned char rooms;
    bool pool;
} VillaData;

typedef union {
    HouseData House;
    ApartmentData Apartment;
    VillaData Villa;
} LocationData;

typedef struct {
    LocationTag tag;
    LocationData data;
} Location;

/*@
    predicate is_house(Location e) = e.tag == House;
    predicate is_villa(Location e) = e.tag == Villa;
    predicate is_apartment(Location e) = e.tag == Apartment;
    
    predicate has_pool(Location e) = 
        is_villa(e) && e.data.Villa.pool;
    predicate has_balcony(Location e) = 
        is_apartment(e) && e.data.Apartment.balcony;
    predicate has_garden(Location e) = 
        is_house(e) && e.data.House.garden;
    
    predicate has_multiple_rooms(Location e) = 
        (is_house(e) && e.data.House.rooms > 1) ||
        (is_apartment(e) && e.data.Apartment.floor > 1) ||
        (is_villa(e) && e.data.Villa.rooms > 1);
    
    lemma verify_multiple_rooms_or_none:
        \forall Location e;
            is_house(e) || is_villa(e) || is_apartment(e) ==>
            (is_house(e) ==> e.data.House.rooms >= 0) &&
            (is_villa(e) ==> e.data.Villa.rooms >= 0) &&
            (is_apartment(e) ==> e.data.Apartment.floor >= 0);
    
    lemma verify_count_or_none:
        \forall Location e;
            has_pool(e) || has_balcony(e) || has_garden(e) ==>
            (has_pool(e) ==> e.data.Villa.pool) &&
            (has_balcony(e) ==> e.data.Apartment.balcony) &&
            (has_garden(e) ==> e.data.House.garden);
*/

int main() {
    return 0;
}
