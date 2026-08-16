// Generated C + ACSL

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Rectangle;

/*@
    requires corners != \null;
    requires corners_len == 8;
    requires \valid(corners + (0 .. corners_len-1));
    requires corners[0] <= corners[4] && corners[1] <= corners[5];
    assigns \nothing;
*/
void find_grid(int* corners, int corners_len)
{
  Point top_left = {corners[0], corners[1]};
  Point bottom_right = {corners[4], corners[5]};
  int board_width = (bottom_right.x - top_left.x);
  int board_height = (bottom_right.y - top_left.y);
  double horizontal_spacing = (board_width / 18.0);
  double vertical_spacing = (board_height / 18.0);
  Rectangle crop_window = {(int)(top_left.x - horizontal_spacing), (int)(top_left.y - vertical_spacing), (int)(board_width + 2.0 * horizontal_spacing), (int)(board_height + 2.0 * vertical_spacing)};
  int board_positions = 0;
  /*@ assert board_positions >= 0 && board_positions <= 2147483647; */
  int x = 0;
/*@
  loop invariant 0 <= x <= 19;
  loop assigns x, board_positions;
  loop variant 19 - x;
*/
  while ((x < 19))
    {
      int row = 0;
      int y = 0;
/*@
  loop invariant 0 <= y <= 19;
  loop assigns y, row;
  loop variant 19 - y;
*/
      while ((y < 19))
        {
          int x_coord = ((int)(top_left.x + horizontal_spacing * x) - crop_window.x);
          int y_coord = ((int)(top_left.y + vertical_spacing * y) - crop_window.y);
          row = (row + 0);
          y = (y + 1);
        }
      board_positions = (board_positions + 0);
      x = (x + 1);
    }
}