# 🎮 Cub3D Development Roadmap: From 2D to 3D

## Phase 1: Project Setup & Basics 🏗️

### 1.1 Environment Setup
```bash
# Essential libraries for cub3d
- MLX42 or MiniLibX (graphics library)
- libft (your library functions)
- Math library (-lm flag)
```

### 1.2 Basic Project Structure
```
cub3d/
├── src/
│   ├── main.c
│   ├── init.c
│   ├── events.c
│   ├── render.c
│   └── utils.c
├── includes/
│   └── cub3d.h
├── maps/
│   └── test.cub
└── Makefile
```

### 1.3 Core Data Structures
```c
typedef struct s_player {
    double x, y;        // Position
    double dir_x, dir_y; // Direction vector
    double plane_x, plane_y; // Camera plane
    double move_speed;
    double rot_speed;
} t_player;

typedef struct s_game {
    void *mlx;
    void *win;
    int **map;          // 2D array of map
    int map_width, map_height;
    t_player player;
    int screen_width, screen_height;
} t_game;
```

## Phase 2: Map Parsing 📋

### 2.1 Map File Format (.cub)
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### 2.2 Parsing Steps
1. **Read file line by line**
2. **Parse texture paths** (NO, SO, WE, EA)
3. **Parse colors** (F for floor, C for ceiling)
4. **Parse map grid** (1=wall, 0=floor, N/S/E/W=player start)
5. **Validate map** (closed by walls, single player, etc.)

## Phase 3: 2D Game Foundation 🎯

### 3.1 Window Initialization
```c
int init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
    // Initialize player position from map
    // Set up event hooks
    return (0);
}
```

### 3.2 Basic Rendering Loop
```c
int render_frame(t_game *game)
{
    // Clear screen
    mlx_clear_window(game->mlx, game->win);
    
    // Draw 2D map (scaled down)
    draw_2d_map(game);
    
    // Draw player
    draw_player(game);
    
    return (0);
}
```

### 3.3 Player Movement System
```c
void handle_movement(t_game *game)
{
    double new_x, new_y;
    
    // Forward/Backward (W/S)
    if (key_pressed(KEY_W)) {
        new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
        new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
        if (is_valid_position(game, new_x, new_y)) {
            game->player.x = new_x;
            game->player.y = new_y;
        }
    }
    
    // Rotation (A/D or Arrow keys)
    if (key_pressed(KEY_A)) {
        rotate_player(game, -ROT_SPEED);
    }
}
```

### 3.4 Collision Detection
```c
int is_valid_position(t_game *game, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;
    
    // Check bounds
    if (map_x < 0 || map_x >= game->map_width || 
        map_y < 0 || map_y >= game->map_height)
        return (0);
    
    // Check if position is a wall
    return (game->map[map_y][map_x] == 0);
}
```

## Phase 4: Advanced 2D Features 🎨

### 4.1 Field of View Visualization
```c
void draw_fov(t_game *game)
{
    double fov_angle = FOV * M_PI / 180; // Convert to radians
    
    // Draw FOV lines
    for (int i = 0; i < NUM_RAYS; i++) {
        double ray_angle = (game->player.angle - fov_angle/2) + 
                          (i * fov_angle / NUM_RAYS);
        
        // Cast ray and draw line
        cast_2d_ray(game, ray_angle);
    }
}
```

### 4.2 Mouse Look Implementation
```c
int handle_mouse(int x, int y, t_game *game)
{
    static int last_x = -1;
    
    if (last_x != -1) {
        int delta_x = x - last_x;
        double rotation = delta_x * MOUSE_SENSITIVITY;
        rotate_player(game, rotation);
    }
    last_x = x;
    return (0);
}
```

## Phase 5: Transition to 3D Raycasting 🌟

### 5.1 Ray Casting Basics
```c
typedef struct s_ray {
    double dir_x, dir_y;    // Ray direction
    double delta_dist_x, delta_dist_y; // Distance between x/y intersections
    double side_dist_x, side_dist_y;   // Distance to next grid line
    int step_x, step_y;     // Step direction
    int hit;                // Wall hit flag
    int side;               // Which side of wall was hit
    double perp_wall_dist;  // Perpendicular distance to wall
} t_ray;
```

### 5.2 DDA Algorithm Implementation
```c
void perform_dda(t_game *game, t_ray *ray, int map_x, int map_y)
{
    while (ray->hit == 0) {
        if (ray->side_dist_x < ray->side_dist_y) {
            ray->side_dist_x += ray->delta_dist_x;
            map_x += ray->step_x;
            ray->side = 0;
        } else {
            ray->side_dist_y += ray->delta_dist_y;
            map_y += ray->step_y;
            ray->side = 1;
        }
        
        if (game->map[map_y][map_x] > 0)
            ray->hit = 1;
    }
}
```

### 5.3 Wall Height Calculation
```c
void calculate_wall_height(t_game *game, t_ray *ray, int *line_height, 
                          int *draw_start, int *draw_end)
{
    *line_height = (int)(game->screen_height / ray->perp_wall_dist);
    *draw_start = -(*line_height) / 2 + game->screen_height / 2;
    *draw_end = (*line_height) / 2 + game->screen_height / 2;
    
    if (*draw_start < 0) *draw_start = 0;
    if (*draw_end >= game->screen_height) *draw_end = game->screen_height - 1;
}
```

## Phase 6: Essential Debugging Tools 🔧

### 6.1 Debug Overlays
- **FPS Counter**: Track performance
- **Player coordinates**: Show exact position
- **Ray visualization**: See individual rays in 2D
- **Map coordinates**: Mouse-over map positions

### 6.2 Debugging Functions
```c
void print_debug_info(t_game *game)
{
    printf("Player: (%.2f, %.2f) Dir: (%.2f, %.2f)\n",
           game->player.x, game->player.y,
           game->player.dir_x, game->player.dir_y);
}
```

## 🎯 Development Milestones Checklist

### Milestone 1: Basic 2D Game ✅
- [ ] Window opens and responds
- [ ] Map loads and displays
- [ ] Player moves with WASD
- [ ] Basic collision detection works
- [ ] ESC key exits cleanly

### Milestone 2: Enhanced 2D ✅
- [ ] Mouse look implemented
- [ ] FOV visualization working
- [ ] Smooth movement and rotation
- [ ] Debug info displays
- [ ] Performance is smooth (60+ FPS)

### Milestone 3: 3D Transition ✅
- [ ] Ray casting implemented
- [ ] Wall heights calculated correctly
- [ ] Basic 3D view renders
- [ ] Both 2D and 3D views work simultaneously

### Milestone 4: Final Polish ✅
- [ ] Textures applied to walls
- [ ] Floor and ceiling colors
- [ ] Proper error handling
- [ ] Memory management (no leaks)
- [ ] Norm compliance

## 💡 Pro Tips for Success

1. **Start Simple**: Get basic movement working before adding complexity
2. **Debug Visually**: Keep your 2D view even in 3D phase
3. **Test Incrementally**: Add one feature at a time
4. **Handle Edge Cases**: Test map boundaries, invalid inputs
5. **Profile Performance**: Use timing functions to find bottlenecks
6. **Memory Management**: Always free allocated memory
7. **Code Organization**: Keep functions small and focused

## 🚨 Common Pitfalls to Avoid

- **Jumping to 3D too early** - Master 2D first
- **Ignoring edge cases** - Test weird map configurations
- **Memory leaks** - Always match malloc with free
- **Poor collision detection** - Can cause frustrating gameplay
- **Frame rate issues** - Optimize rendering loops
- **Norm violations** - Check regularly with norminette