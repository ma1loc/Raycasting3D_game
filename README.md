# Cub3D Ray-Casting Engine 🎮

**A 3D game engine built from scratch using ray-casting magic!**

Welcome to my Cub3D project! This is a journey through the fascinating world of ray-casting - the same technique that powered legendary games like Wolfenstein 3D. I've built this engine step by step, and I'm excited to share the results with you.


### 📚 Interactive Ray-Casting Learning Resource

I've DONE all the ray-casting and developed a comprehensive visual guide that demonstrates the fundamental principles of ray-casting algorithms. This interactive educational tool provides step-by-step breakdowns of the mathematical concepts and implementation strategies.  
Created by Me: (@ma1loc) =>  **[🔗 Access Ray-Casting Tutorial](https://www.tldraw.com/p/nrxBdkny-lr8txkRoSnyt?d=v4168.-4136.38400.21600.eLz4W7KpaMOCqJI7W8QwN)**


---

## What is Ray-Casting? 🔍

Ray-casting is a brilliant technique that creates the illusion of 3D environments from 2D maps. Imagine casting invisible rays from your eyes in all directions - wherever they hit a wall, that's what you see! It's like having mathematical superpowers that turn flat maps into immersive 3D worlds.

---

## My Implementation Journey 🚀

I've approached this project in three exciting phases, each building upon the previous one. Here's how the magic unfolds:

### Phase 1: The Foundation - 2D Ray-Casting ⚡

This is where everything begins! I implemented the core ray-casting algorithm and visualized it in 2D so you can actually see the rays being cast from the player's position.

## This is the 2D Ray-casting implementation result
https://github.com/user-attachments/assets/fa174c88-97f1-4718-a29f-38895e538293

**What you'll see:**
- Rays shooting out from the player position
- Real-time intersection detection with walls
- The mathematical foundation that makes everything possible

### Phase 2: Going 3D - The Projection Magic 🎯

Here's where things get really exciting! I transformed those 2D calculations into a proper 3D environment. You can walk around and experience the world in three dimensions.

## This is the 3D projection implementation before adding the textures
https://github.com/user-attachments/assets/d7e90b48-bda2-4013-90ae-1e346636f219

**What you'll see:**
- Full 3D environment with proper perspective
- Smooth player movement and rotation
- Walls that get taller or shorter based on distance

### Phase 3: The Final Touch - Textured Perfection ✨

The grand finale! I added beautiful textures to bring the world to life. This is where the engine truly shines and feels like a real game.

## This is the 3D projection implementation after adding the textures
https://github.com/user-attachments/assets/d625efba-4a2b-4e3c-b9da-1ff2b2f52658

**What you'll see:**
- Gorgeous textured walls
- A fully immersive 3D environment
- The complete ray-casting experience

---

## The Technical Magic Behind the Scenes 🔧

### Ray-Casting Algorithm
The heart of the engine uses the **DDA (Digital Differential Analyzer)** algorithm to efficiently detect where rays hit walls. It's like having a super-fast mathematical detective that finds intersections in milliseconds!

### Key Features That Make It Special:
- **Fisheye Correction**: No weird distortions - everything looks natural
- **Perspective Perfection**: Walls scale correctly based on distance
- **Smooth Performance**: Optimized for real-time rendering
- **Texture Mapping**: Beautiful textures mapped precisely to wall surfaces

### Mathematical Concepts I Used:
- **Trigonometry**: For calculating ray directions and angles
- **Linear Algebra**: Vector math for 3D transformations  
- **Coordinate Geometry**: Converting between different coordinate systems
- **Optimization Techniques**: Making everything run smoothly

---

## How to Experience It 🎮

**Controls:**
- **W/A/S/D**: Move around the world
- **←/→ Arrow Keys**: Look left and right
- **ESC**: Exit when you're done exploring

**Installation:**
```bash
# Clone and enter the project
git clone https://github.com/ma1loc/Raycasting3D_game.git
cd Raycasting3D_game

# Build the engine
make

# Launch with a map
./cub3d maps/main_map.cub
```

---

## What Makes This Project Special 🌟

### Technical Excellence
- **Built from scratch** - Every line of code crafted with care
- **Mathematical precision** - Accurate calculations for perfect visuals
- **Performance optimized** - Smooth gameplay experience
- **Clean architecture** - Well-organized, maintainable code

### Learning Journey
This project taught me so much about:
- **Computer Graphics Fundamentals** - How 3D graphics really work
- **Algorithm Implementation** - Turning theory into working code
- **Performance Optimization** - Making real-time graphics smooth
- **Problem Solving** - Overcoming complex technical challenges

### Real-World Applications
The skills demonstrated here are directly applicable to:
- **Game Engine Development** 🎮
- **3D Visualization Software** 📊
- **Simulation Systems** 🔬
- **Graphics Programming** 🎨

---

## Future Enhancements 🚀

I'm always thinking about how to make this even better:
- **Sprites and Objects**: Adding 3D enemies and items
- **Floor and Ceiling Textures**: Complete environment texturing
- **Dynamic Lighting**: Shadows and atmospheric lighting
- **Sound System**: Immersive 3D audio
- **Multiple Levels**: Different maps and environments

---

## Why I Built This 💡

Ray-casting fascinated me because it's where mathematics meets visual artistry. There's something magical about transforming abstract mathematical concepts into immersive visual experiences. This project represents hundreds of hours of learning, coding, debugging, and refining - and I loved every minute of it!

It's not just about the final result; it's about understanding how the graphics in our favorite games actually work under the hood. When you see those textured walls in the final demo, you're witnessing pure mathematics transformed into visual reality.

---

## Connect With Me 🤝
I'm passionate about graphics programming and always excited to discuss technical challenges, share knowledge, or collaborate on interesting projects. Feel free to explore the code, ask questions, or share your thoughts!

---

*"Ray-casting: Where mathematics becomes magic, and flat worlds become infinite possibilities."* ✨

**Thank you for checking out my Cub3D engine! I hope you enjoy exploring the demos as much as I enjoyed building them.** 🎉
