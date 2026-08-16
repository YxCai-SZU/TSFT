#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>

/* ========== Original function 1: compute grid intersect points ========== */

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer target_value(integer n, integer m) =
        n * m - (n - 1) - (m - 1);
*/

int func1(int n, int m)
{
    int result;
    int temp;
    int i;

    //@ assert valid_range(n, m);
    //@ assert 1 <= n * m <= 400;

    result = n * m;

    temp = result;
    i = 0;
    while (i < n - 1)
    {
        temp -= 1;
        i += 1;
    }
    result = temp;

    temp = result;
    i = 0;
    while (i < m - 1)
    {
        temp -= 1;
        i += 1;
    }
    result = temp;

    //@ assert result == target_value(n, m);
    return result;
}

/* ========== Original function 2: compute combined min and max diff ========== */

/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    logic integer abs_diff(integer x, integer y) =
        x >= y ? x - y : y - x;

    logic integer max(integer x, integer y) =
        x >= y ? x : y;
*/

int func2(int a, int b, int c, int d)
{
    int result = 0;
    int diff;
    int diff2;
    int max_diff;

    //@ assert bounds(a, b, c, d);

    if (a < b)
    {
        result += a;
    }
    else
    {
        result += b;
    }

    //@ assert result >= 0 && result <= a + b;

    if (c < d)
    {
        result += c;
    }
    else
    {
        result += d;
    }

    //@ assert result >= 0 && result <= a + b + c + d;

    diff = (a - b < 0) ? -(a - b) : (a - b);
    diff2 = (c - d < 0) ? -(c - d) : (c - d);
    max_diff = (diff > diff2) ? diff : diff2;
    result += max_diff;

    //@ assert result >= 0;
    //@ assert result <= a + b + c + d;

    return result;
}

/* ========== Original function 3: compute residual after array sum ========== */

/*@ predicate valid_array(int *arr, integer len) =
      len >= 1 && len <= 10000 &&
      \forall integer i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 10000;
*/


int func3(int n, int *a, int a_len) {
    int sum = 0;
    size_t i = 0;
    int ans = 0;

    //@ assert valid_array(a, a_len);
    
    while (i < (size_t)a_len && i < 10000) {
        //@ assert i >= 0 && i < a_len;
        sum += a[i];
        i++;
        //@ assert sum >= 0;
    }

    //@ assert sum >= 0;
    
    if (n >= sum) {
        ans = n - sum;
    } else {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= n;
    return ans;
}

/* ========== Original function 4: check tomato ripeness (simplified) ========== */

typedef struct {
    bool is_ripe;
    char* color;
} Tomato;

typedef struct {
    bool is_sour;
    unsigned short length;
} Cucumber;

typedef struct {
    bool is_organic;
    int beta_carotene;
} Carrot;

typedef enum {
    TOMATO,
    CUCUMBER,
    CARROT
} VegetableTag;

typedef struct {
    VegetableTag tag;
    union {
        Tomato tomato;
        Cucumber cucumber;
        Carrot carrot;
    };
} Vegetable;

/*@ predicate is_tomato(Vegetable v) = v.tag == TOMATO; */
/*@ predicate is_cucumber(Vegetable v) = v.tag == CUCUMBER; */
/*@ predicate is_carrot(Vegetable v) = v.tag == CARROT; */

/*@ predicate is_ripe_tomato(Vegetable v) = 
      is_tomato(v) && v.tomato.is_ripe; */

bool check_tomato_func(Vegetable p) {
    //@ assert is_tomato(p);
    //@ assert !is_cucumber(p);
    return p.tomato.is_ripe;
}

/* ========== Synthesized function: Salad Quality Matrix ========== */

int synthesize_salad_quality(int n, int m, int a, int b, int c, int d,
                             int n_input, int *arr, int arr_len, Vegetable v)
{
    int grid_intersections = func1(n, m);
    //@ assert grid_intersections == target_value(n, m);
    
    int nutrient_potential = func2(a, b, c, d);
    //@ assert nutrient_potential >= 0 && nutrient_potential <= a + b + c + d;
    
    int waste_residual = func3(n_input, arr, arr_len);
    //@ assert waste_residual >= 0 && waste_residual <= n_input;
    
    bool is_ripe = check_tomato_func(v);
    //@ assert is_ripe == v.tomato.is_ripe;
    
    int quality = grid_intersections * (is_ripe ? 1 : 0) + nutrient_potential - waste_residual;
    
    //@ assert quality >= -1000000 && quality <= 800;
    return quality;
}
