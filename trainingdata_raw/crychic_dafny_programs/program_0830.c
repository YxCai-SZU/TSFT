// Generated C + ACSL

/*@
  predicate Valid(integer height, integer length, integer units, integer direction,
                  integer x_pos, integer play_screen_x, integer play_width,
                  integer BLOCK_SIZE) =
    height == BLOCK_SIZE &&
    length == BLOCK_SIZE * units &&
    (direction == 1 || direction == -1) &&
    x_pos >= play_screen_x &&
    x_pos <= play_screen_x + play_width - length &&
    units > 0 &&
    play_screen_x >= 0 &&
    play_width > 0 &&
    BLOCK_SIZE > 0;
*/

int x_pos, y_pos, height, length, direction, play_screen_x, play_width, is_moving, pos_x, pos_y, h, len;
#define BLOCK_SIZE 10

/*@
    requires Valid(height, length, length / BLOCK_SIZE, direction, x_pos, play_screen_x, play_width, BLOCK_SIZE);
    assigns x_pos, direction;
    ensures Valid(height, length, length / BLOCK_SIZE, direction, x_pos, play_screen_x, play_width, BLOCK_SIZE);
    ensures is_moving == \old(is_moving);
    ensures x_pos >= play_screen_x;
    ensures x_pos <= play_screen_x + play_width - length;
    ensures direction == 1 || direction == -1;
*/
void move_block(void)
{
  int new_x = (x_pos + (direction * BLOCK_SIZE));
  if ((new_x < play_screen_x))
  {
    x_pos = play_screen_x;
    /*@ assert x_pos >= play_screen_x && play_screen_x >= 0; */
    direction = 1;
    /*@ assert direction == 1; */
  }
  else
  if ((new_x > ((play_screen_x + play_width) - length)))
  {
    x_pos = ((play_screen_x + play_width) - length);
    /*@ assert x_pos >= play_screen_x; */
    direction = -1;
    /*@ assert direction == -1; */
  }
  else
  {
    x_pos = new_x;
    /*@ assert x_pos >= play_screen_x; */
  }
  /*@ assert direction == 1 || direction == -1; */
  /*@ assert x_pos >= play_screen_x; */
}

/*@
    requires Valid(height, length, length / BLOCK_SIZE, direction, x_pos, play_screen_x, play_width, BLOCK_SIZE);
    requires y_pos >= 0;
    assigns is_moving, pos_x, pos_y, h, len;
    ensures is_moving == 0;
    ensures pos_x == \old(x_pos);
    ensures pos_y == \old(y_pos);
    ensures h == \old(height);
    ensures len == \old(length);
    ensures Valid(\old(height), \old(length), \old(length) / BLOCK_SIZE, \old(direction), \old(x_pos), play_screen_x, play_width, BLOCK_SIZE);
*/
void freeze(void)
{
  is_moving = 0;
  /*@ assert is_moving == 0; */
  pos_x = x_pos;
  /*@ assert pos_x == x_pos && x_pos >= play_screen_x && play_screen_x >= 0; */
  pos_y = y_pos;
  /*@ assert pos_y == y_pos && y_pos >= 0; */
  h = height;
  /*@ assert h == height && height == BLOCK_SIZE && BLOCK_SIZE > 0; */
  len = length;
  /*@ assert len == length && length > 0; */
}