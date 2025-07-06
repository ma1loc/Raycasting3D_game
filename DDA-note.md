# DDA Algorithm Guide for cub3d Project

## Table of Contents
1. [Introduction](#introduction)
2. [Mathematical Foundation](#mathematical-foundation)
3. [DDA Algorithm Explained](#dda-algorithm-explained)
4. [Implementation for cub3d](#implementation-for-cub3d)
5. [Step-by-Step Walkthrough](#step-by-step-walkthrough)
6. [Code Examples](#code-examples)
7. [Common Pitfalls and Solutions](#common-pitfalls-and-solutions)
8. [Optimization Tips](#optimization-tips)
9. [Testing and Debugging](#testing-and-debugging)

## Introduction

The Digital Differential Analyzer (DDA) is a line-drawing algorithm that's essential for raycasting in 3D graphics. In the cub3d project, DDA helps us determine which wall a ray hits first by stepping through grid cells efficiently.

**Why DDA for cub3d?**
- Efficiently traverses grid-based maps
- Determines exact wall collision points
- Calculates distances for proper wall rendering
- Handles both horizontal and vertical wall detection

## Mathematical Foundation

### Grid System
Your cub3d map is a 2D grid where:
- Each cell represents either empty space (0) or a wall (1)
- Player position is in world coordinates (float values)
- Grid coordinates are integers

### Ray Representation
A ray is defined by:
- **Origin**: Player position (px, py)
- **Direction**: Unit vector (dx, dy) based on viewing angle
- **Equation**: Point = Origin + t × Direction

### Key Concepts
- **Delta distances**: How far the ray travels to cross one grid line
- **Side distances**: Current distance to next grid line
- **Step direction**: Which way to move in the grid (+1 or -1)

## DDA Algorithm Explained

### Core Principle
Instead of checking every point along the ray, DDA jumps from grid line to grid line, checking only the cells that the ray actually enters.

### Algorithm Steps
1. **Initialize**: Calculate initial values and directions
2. **Step**: Move to the next grid line (either x or y)
3. **Check**: Test if current cell contains a wall
4. **Repeat**: Continue until wall is found
5. **Calculate**: Determine exact hit point and distance

### Visual Representation
```
Grid:     Ray Path:
+---+---+    +---+---+
|   | 1 |    |   |///|  <- Hit wall here
+---+---+    +---+---+
| 0 | 0 |    |*--+---+  <- Ray starts here
+---+---+    +---+---+
```

## Implementation for cub3d

### Data Structure
```c
typedef struct s_ray {
    double  pos_x;        // Ray start position
    double  pos_y;
    double  dir_x;        // Ray direction
    double  dir_y;
    int     map_x;        // Current grid position
    int     map_y;
    double  delta_dist_x; // Distance to travel for x-side
    double  delta_dist_y; // Distance to travel for y-side
    double  side_dist_x;  // Distance to next x-side
    double  side_dist_y;  // Distance to next y-side
    int     step_x;       // Step direction for x
    int     step_y;       // Step direction for y
    int     hit;          // Was a wall hit?
    int     side;         // Which side was hit? (0=x-side, 1=y-side)
    double  wall_dist;    // Distance to wall
} t_ray;
```

### Initialization Phase
```c
void init_ray(t_ray *ray, double pos_x, double pos_y, double dir_x, double dir_y)
{
    ray->pos_x = pos_x;
    ray->pos_y = pos_y;
    ray->dir_x = dir_x;
    ray->dir_y = dir_y;
    
    // Current grid position
    ray->map_x = (int)pos_x;
    ray->map_y = (int)pos_y;
    
    // Delta distances (how far to travel to cross one grid line)
    ray->delta_dist_x = fabs(1.0 / dir_x);
    ray->delta_dist_y = fabs(1.0 / dir_y);
    
    ray->hit = 0;
}
```

### Step Direction and Initial Side Distances
```c
void calculate_step_and_side_dist(t_ray *ray)
{
    if (ray->dir_x < 0) {
        ray->step_x = -1;
        ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
    } else {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
    }
    
    if (ray->dir_y < 0) {
        ray->step_y = -1;
        ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
    } else {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
    }
}
```

## Step-by-Step Walkthrough

### Example Scenario
- Player at position (1.5, 1.5)
- Ray direction (0.6, 0.8)
- Grid with wall at (3, 2)

### Step 1: Initialization
- map_x = 1, map_y = 1
- delta_dist_x = 1/0.6 = 1.667
- delta_dist_y = 1/0.8 = 1.25

### Step 2: Calculate Steps
- dir_x > 0, so step_x = 1
- dir_y > 0, so step_y = 1
- side_dist_x = (2 - 1.5) × 1.667 = 0.833
- side_dist_y = (2 - 1.5) × 1.25 = 0.625

### Step 3: DDA Loop
```
Iteration 1:
- side_dist_y (0.625) < side_dist_x (0.833)
- Move in y-direction: map_y = 2
- side_dist_y += delta_dist_y = 1.875
- Check map[1][2] - empty, continue

Iteration 2:
- side_dist_x (0.833) < side_dist_y (1.875)
- Move in x-direction: map_x = 2
- side_dist_x += delta_dist_x = 2.5
- Check map[2][2] - empty, continue

Iteration 3:
- side_dist_y (1.875) < side_dist_x (2.5)
- Move in y-direction: map_y = 3
- Check map[2][3] - wall found!
```

### Step 4: Distance Calculation
```c
if (ray->side == 0) // x-side hit
    ray->wall_dist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
else // y-side hit
    ray->wall_dist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
```

## Code Examples

### Complete DDA Implementation
```c
void perform_dda(t_ray *ray, int **map)
{
    while (ray->hit == 0) {
        // Jump to next map square, either in x-direction, or in y-direction
        if (ray->side_dist_x < ray->side_dist_y) {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0; // x-side
        } else {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1; // y-side
        }
        
        // Check if ray has hit a wall
        if (map[ray->map_x][ray->map_y] > 0)
            ray->hit = 1;
    }
    
    // Calculate distance
    if (ray->side == 0)
        ray->wall_dist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
    else
        ray->wall_dist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
}
```

### Integration with Raycasting
```c
void cast_rays(t_game *game)
{
    int x;
    
    for (x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate ray direction
        double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        double ray_dir_x = game->dir_x + game->plane_x * camera_x;
        double ray_dir_y = game->dir_y + game->plane_y * camera_x;
        
        // Initialize and perform DDA
        t_ray ray;
        init_ray(&ray, game->pos_x, game->pos_y, ray_dir_x, ray_dir_y);
        calculate_step_and_side_dist(&ray);
        perform_dda(&ray, game->map);
        
        // Use ray.wall_dist for wall height calculation
        int wall_height = (int)(SCREEN_HEIGHT / ray.wall_dist);
        // ... render wall strip
    }
}
```

## Common Pitfalls and Solutions

### 1. Division by Zero
**Problem**: Ray direction components can be zero
**Solution**: 
```c
if (dir_x == 0)
    delta_dist_x = 1e30; // Very large number
else
    delta_dist_x = fabs(1.0 / dir_x);
```

### 2. Infinite Loops
**Problem**: Ray never hits a wall
**Solution**: Add boundary checks
```c
if (ray->map_x < 0 || ray->map_x >= MAP_WIDTH || 
    ray->map_y < 0 || ray->map_y >= MAP_HEIGHT) {
    ray->hit = 1; // Treat boundary as wall
}
```

### 3. Floating Point Precision
**Problem**: Rays can miss thin walls
**Solution**: Use consistent epsilon values
```c
#define EPSILON 1e-9
if (fabs(value) < EPSILON) value = 0;
```

### 4. Wrong Wall Side Detection
**Problem**: Lighting/texturing issues
**Solution**: Ensure side variable is set correctly in DDA loop

## Optimization Tips

### 1. Precalculate Delta Distances
Store delta distances in lookup tables for common angles.

### 2. Integer Arithmetic
Use fixed-point arithmetic where possible to avoid floating-point operations.

### 3. Early Termination
Stop DDA when maximum view distance is reached.

### 4. Vectorization
Process multiple rays simultaneously using SIMD instructions.

## Testing and Debugging

### Debug Visualization
```c
void debug_ray(t_ray *ray)
{
    printf("Ray: pos(%.2f,%.2f) dir(%.2f,%.2f)\n", 
           ray->pos_x, ray->pos_y, ray->dir_x, ray->dir_y);
    printf("Hit: %d at (%d,%d) side:%d dist:%.2f\n",
           ray->hit, ray->map_x, ray->map_y, ray->side, ray->wall_dist);
}
```

### Test Cases
1. **Horizontal rays**: dir_y = 0
2. **Vertical rays**: dir_x = 0
3. **Diagonal rays**: dir_x = dir_y
4. **Edge cases**: Rays starting exactly on grid lines

### Validation
- Verify wall distances are always positive
- Check that hit coordinates are within map bounds
- Ensure side detection matches expected wall orientation

## Performance Considerations

### Memory Access Patterns
- Access map data in cache-friendly order
- Use row-major order for 2D arrays
- Consider map data structure (array vs. pointer-to-pointer)

### Algorithmic Optimizations
- Use bit operations for step direction calculations
- Implement fast square root for distance calculations
- Consider using lookup tables for trigonometric functions

## Conclusion

The DDA algorithm is the heart of efficient raycasting in cub3d. Understanding its mathematical foundation and implementation details is crucial for creating a smooth, bug-free 3D renderer. Focus on getting the basic algorithm working correctly first, then optimize for performance as needed.

Remember that DDA is just one part of the raycasting pipeline - you'll also need to handle texture mapping, sprite rendering, and other graphics tasks to complete your cub3d project successfully.