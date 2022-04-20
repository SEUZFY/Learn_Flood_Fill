# Learn_Flood_Fill

Flood fill algorithm from: https://www.algorithm-archive.org/contents/flood_fill/flood_fill.html.

# TEST

Need to explicitly define the **start position**, it determines which side of the boundary in the matrix will be filled.

* Example

  **input matrix**:
  
        {
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0}
        }        
  The boundary consists of `1`.
  
  **-> Fill the left side**:
        
  set `start_left_pos` to `(0, 2)` - - an arbitrary position on the left side (NOT on the boundary)
  
  The solution matrix (with left side filled):
  
        {
        {1, 1, 1, 1, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 0}
        }
        
  **-> Fill the right side**:
        
  set `start_right_pos` to `(1, 3)` - - an arbitrary position on the right side (NOT on the boundary)
  
  The solution matrix (with right side filled):
  
        {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
        }
