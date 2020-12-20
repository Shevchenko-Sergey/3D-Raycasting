# 3D-Raycasting
Wolfenstein 3D simple remake

Linux only.

1. sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
2. cd mlx_linux && make
3. copy libmlx.a in /usr/local/lib
   copy mlx.h in /usr/local/include
4. cd to main path && make

Run:

./cub3D map.cub

Screenshot:

./cub3D map.cub --save

Configuration file map.cub:

R - window resolution
F - floor color
C - ceiling color

WE, EA, NO, SO - textures path according side of the world

0 - empty map
1 - walls
2 - sprites
W (or N, E, S) - player on the map and his direction
