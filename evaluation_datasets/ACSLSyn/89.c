#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_vec(int *v) =
      \valid(v + (0..2)) &&
      (\forall integer i; 0 <= i < 3 ==> 1 <= v[i] && v[i] <= 100);
*/

/*@ logic integer color_count_logic(int *v) =
      v[0] == v[1] && v[0] == v[2] ? 1 :
      v[0] == v[1] || v[1] == v[2] || v[0] == v[2] ? 2 : 3;
*/

/*@ lemma all_equal_case:
      \forall int *v; valid_vec(v) && v[0] == v[1] && v[0] == v[2] ==> color_count_logic(v) == 1;
*/

/*@ lemma two_equal_case:
      \forall int *v; valid_vec(v) && (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) && 
      !(v[0] == v[1] && v[0] == v[2]) ==> color_count_logic(v) == 2;
*/

/*@ lemma all_distinct_case:
      \forall int *v; valid_vec(v) && v[0] != v[1] && v[1] != v[2] && v[0] != v[2] ==> 
      color_count_logic(v) == 3;
*/

/*@ lemma bounds_lemma:
      \forall int *v; valid_vec(v) ==> 1 <= color_count_logic(v) && color_count_logic(v) <= 3;
*/

int func(int *v)
{
    //@ assert v[0] == v[1] && v[0] == v[2] || v[0] == v[1] || v[1] == v[2] || v[0] == v[2] || (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]);
    
    if (v[0] == v[1] && v[0] == v[2]) {
        //@ assert v[0] == v[1] && v[1] == v[2];
        return 1;
    } else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2]) {
        //@ assert v[0] == v[1] || v[1] == v[2] || v[0] == v[2];
        return 2;
    } else {
        //@ assert v[0] != v[1] && v[1] != v[2] && v[0] != v[2];
        return 3;
    }
}

/*@
    predicate valid_params(integer N, integer M) =
        2 <= N && N <= 100 &&
        2 <= M && M <= 100;

    logic integer compute_result(integer N, integer M) =
        (N - 1) * (M - 1);

    lemma bounds_lemma2:
        \forall integer N, M;
        valid_params(N, M) ==>
        0 <= N-1 && N-1 <= 99 &&
        0 <= M-1 && M-1 <= 99;

    lemma product_bound_lemma:
        \forall integer N, M;
        0 <= N && N <= 99 &&
        0 <= M && M <= 99 ==>
        N * M <= 99 * 99;
*/

int64_t func2(int64_t N, int64_t M)
{
    int64_t n_adjusted;
    int64_t m_adjusted;
    
    //@ assert valid_params(N, M);
    
    n_adjusted = (N < 0) ? 0 : (N - 1);
    m_adjusted = (M < 0) ? 0 : (M - 1);
    
    //@ assert 0 <= n_adjusted && n_adjusted <= 99;
    //@ assert 0 <= m_adjusted && m_adjusted <= 99;
    //@ assert n_adjusted * m_adjusted <= 99 * 99;
    
    return n_adjusted * m_adjusted;
}

/*@
    predicate valid_game_state(int *grid, int64_t N, int64_t M) =
        valid_vec(grid) &&
        valid_params(N, M) &&
        color_count_logic(grid) == 1;
*/

int64_t process_game_board(int *grid, int64_t N, int64_t M)
{
    //@ assert valid_vec(grid);
    //@ assert valid_params(N, M);
    //@ assert color_count_logic(grid) == 1;
    
    int color_count = func(grid);
    //@ assert color_count == 1;
    //@ assert color_count_logic(grid) == 1;
    
    //@ assert valid_params(N, M);
    int64_t result = func2(N, M);
    //@ assert result == (N - 1) * (M - 1);
    //@ assert 0 <= result && result <= 99 * 99;
    
    //@ assert color_count == 1 && result == (N - 1) * (M - 1);
    return result;
}
