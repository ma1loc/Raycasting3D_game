# 🖥️ MiniLibX Setup Guide for Cub3D

## 📦 Which Version Should You Use?

You have 3 different versions - here's the breakdown:

### **minilibx-linux.tgz** ⭐ **RECOMMENDED**
- **Best for**: 42 School projects, Linux systems
- **Pros**: Most stable, widely used, good documentation
- **Cons**: Linux only
- **Use if**: You're on Linux or using 42 school computers

### **minilibx_opengl.tgz** 
- **Best for**: Cross-platform development, better performance
- **Pros**: Works on macOS/Linux, hardware acceleration
- **Cons**: More complex setup, potential compatibility issues
- **Use if**: You need cross-platform support

### **minilibx_mms_20200219_beta.tgz**
- **Best for**: macOS development
- **Pros**: Native macOS support
- **Cons**: Beta version, might have bugs
- **Use if**: You're specifically on macOS

## 🚀 Installation Steps

### For Linux (Recommended: minilibx-linux.tgz)

#### Step 1: Extract and Install Dependencies
```bash
# Extract the archive
tar -xzf minilibx-linux.tgz
cd minilibx-linux

# Install dependencies (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# For other distributions:
# CentOS/RHEL: sudo yum install gcc make xorg-x11-server-devel libXext-devel
# Arch: sudo pacman -S gcc make xorg-server-devel libxext
```

#### Step 2: Compile MiniLibX
```bash
# In the minilibx-linux directory
make

# This should create:
# - libmlx.a (static library)
# - libmlx_Linux.a (alternative name)
```

#### Step 3: Test Installation
```bash
# Compile a test program
gcc -Wall -Wextra -Werror test/mlx-test.c -L. -lmlx -lXext -lX11 -lm -o test
./test
```

### For macOS (Use minilibx_mms_20200219_beta.tgz)

#### Step 1: Extract and Setup
```bash
tar -xzf minilibx_mms_20200219_beta.tgz
cd minilibx_mms_20200219_beta

# Compile
make

# This creates libmlx.a
```

#### Step 2: Test Installation
```bash
gcc -Wall -Wextra -Werror test/mlx-test.c -L. -lmlx -framework OpenGL -framework AppKit -o test
./test
```

## 🏗️ Project Integration

### Directory Structure
```
cub3d/
├── minilibx-linux/          # Your chosen MLX version
│   ├── libmlx.a
│   ├── mlx.h
│   └── mlx_int.h
├── src/
│   ├── main.c
│   ├── init.c
│   └── ...
├── includes/
│   └── cub3d.h
└── Makefile
```

### Makefile Setup

```makefile
# Cub3D Makefile
NAME = cub3d

# Directories
SRC_DIR = src
INC_DIR = includes
MLX_DIR = minilibx-linux

# Files
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/init.c \
       $(SRC_DIR)/events.c \
       $(SRC_DIR)/render.c \
       $(SRC_DIR)/utils.c

OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INC_DIR) -I$(MLX_DIR)

# Libraries
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# For macOS, use these instead:
# LIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Rules
all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
```

## 🧪 Basic Test Program

Create this test file to verify everything works:

### src/main.c
```c
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
    void *mlx;
    void *win;
} t_data;

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

int key_hook(int keycode, t_data *data)
{
    printf("Key pressed: %d\n", keycode);
    if (keycode == 65307) // ESC key
        close_window(data);
    return (0);
}

int main(void)
{
    t_data data;
    
    // Initialize MLX
    data.mlx = mlx_init();
    if (!data.mlx)
    {
        printf("Error: MLX initialization failed\n");
        return (1);
    }
    
    // Create window
    data.win = mlx_new_window(data.mlx, 800, 600, "Cub3D Test");
    if (!data.win)
    {
        printf("Error: Window creation failed\n");
        return (1);
    }
    
    // Set up event hooks
    mlx_key_hook(data.win, key_hook, &data);
    mlx_hook(data.win, 17, 0, close_window, &data); // Close button
    
    printf("Test window created successfully!\n");
    printf("Press ESC to exit\n");
    
    // Start event loop
    mlx_loop(data.mlx);
    
    return (0);
}
```

### includes/cub3d.h
```c
#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define FOV 60
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

// Key codes (Linux X11)
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// For macOS, use these instead:
// # define KEY_W 13
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define KEY_ESC 53

typedef struct s_player {
    double x;
    double y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
} t_player;

typedef struct s_game {
    void *mlx;
    void *win;
    t_player player;
    int **map;
    int map_width;
    int map_height;
} t_game;

// Function prototypes
int init_game(t_game *game);
int handle_keypress(int keycode, t_game *game);
int render_frame(t_game *game);
void cleanup_game(t_game *game);

#endif
```

## 🔧 Compilation Test

```bash
# Compile your test
make

# Run it
./cub3d

# You should see:
# - A window opens (800x600)
# - "Test window created successfully!" message
# - Window responds to ESC key
# - No errors or crashes
```

## 🚨 Common Issues & Solutions

### Issue 1: "mlx.h not found"
```bash
# Solution: Check your include path
# Make sure -I$(MLX_DIR) is in your CFLAGS
```

### Issue 2: "undefined reference to mlx_init"
```bash
# Solution: Check linking flags
# Linux: -lmlx -lXext -lX11 -lm
# macOS: -lmlx -framework OpenGL -framework AppKit
```

### Issue 3: "cannot open display"
```bash
# Solution: If using SSH or WSL
export DISPLAY=:0
# Or use X11 forwarding: ssh -X username@host
```

### Issue 4: Permission denied
```bash
# Solution: Make sure you have execution permissions
chmod +x cub3d
```

## 📋 Next Steps Checklist

- [ ] Extract and compile your chosen MLX version
- [ ] Create basic project structure
- [ ] Set up Makefile with proper linking
- [ ] Compile and run the test program
- [ ] Verify window opens and responds to ESC
- [ ] Move on to implementing map parsing

## 💡 Pro Tips

1. **Always test MLX first** - Don't build your entire project on a broken setup
2. **Use the right key codes** - They differ between Linux and macOS
3. **Handle window close properly** - Always set up the close hook
4. **Check for memory leaks** - Use `valgrind` on Linux
5. **Keep backups** - MLX can be finicky to reinstall

Ready to proceed? Run the test program first, then let me know if you encounter any issues!