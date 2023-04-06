# 🪙🎮🍄 So_long
<p>
  <img src="Score_So_long.png" alt="Score So_long 102/100" align="left">

 <br><br>
We worked on a small 2D game project using minilibx, where we learned about textures, sprites, and tiles.
<br><br>
<br><br>
</p>
This is my solution for the so_long project of the core curriculum of 42 school.<br>

## Explanation of the project

This projects goal is to create your own 2D game where you have a map that can have different dimensions and contents.<br>

### Requirements to run the game
Only tested on **macOS Catalina (Version 10.15.7)**.<br>
For all other OS it is not guaranteed to work.<br>
OpenGL and AppKit is required to run it.<br>

### Map
A valid map is structured as followed:<br>
- 1 player (`P`)
- 1 exit (`E`)
- at least 1 collectible (`C`)`
- is recatangular
- has a solid outside border out of walls (`1`)
- all the empty spaces are filled with `0`
- map has to be `.ber`
- no other characters than:
  * `P`
  * `E`
  * `C`
  * `1`
  * `0`
- i.e. `map1.ber`:
- one new line after the map is valid, if there is anything else, it is not valid

```
1111111111111
10010000000C1
1000011111001
1P0011E000011
1111111111111
```

<br>

### During the game
The player can only be moved by `WASD` or 'arrow'.<br>
The player can not move into walls.<br>
The player can only exit if all collectibles are collected.<br>
The amount of movements is counted and displayed in the terminal.<br>
Every try to move even if it is invalid will be counted as one move.<br>

All the visualization is done with the help of the [MiniLibX library](https://github.com/tblaase/so_long/tree/master/mlx "https://github.com/tblaase/so_long/tree/master/mlx").<br>

## How to run the game

All of the commands should be run in the root of the directory.<br>
- make -C minilibx-linux
- make
- run the game with `./so_long map1.ber`

This is how the game looks for the map6.ber.<br>

<img src="Example_map.png" width="800"/><br>

During the game we write the number of moves in the terminal. 

You can close the window with the cross or the escape key.<br>

# Thank you and bye.👋
<center>
<p>
⬜⬜⬜⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜⬜⬜<br>
⬜⬜⬜⬜⬜⬛⬛🟥🟥🟥🟥⬛⬛⬜⬜⬜⬜⬜<br>
⬜⬜⬜⬜⬛🟥🟥🟥⬜⬜🟥🟥🟥⬛⬜⬜⬜⬜<br>
⬜⬜⬜⬛🟥🟥🟥⬜⬜⬜⬜🟥🟥🟥⬛⬜⬜⬜<br>
⬜⬜⬛🟥🟥🟥⬛⬛⬛⬛⬛⬛🟥🟥🟥⬛⬜⬜<br>
⬜⬜⬛🟥🟥⬛⬛⬛⬛⬛⬛⬛⬛🟥🟥⬛⬜⬜<br>
⬜⬜⬛🟥⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛🟥⬛⬜⬜<br>
⬜⬜⬛🟥⬛⬛⬜⬜🏻🏻⬜⬜⬛⬛🟥⬛⬜⬜<br>
⬜⬜⬛⬛🏻🏻⬜⬛🏻🏻⬛⬜🏻🏻⬛⬛⬜⬜<br>
⬜⬛🏻⬛🏻🏻⬜⬛🏻🏻⬛⬜🏻🏻⬛🏻⬛⬜<br>
⬜⬛🏻⬛⬛🏻🏻🏻🏻🏻🏻🏻🏻⬛⬛🏻⬛⬜<br>
⬜⬜⬛⬛🏻⬛⬛🏻🏻🏻🏻⬛⬛🏻⬛⬛⬜⬜<br>
⬜⬜⬜⬛🏻⬛⬛⬛⬛⬛⬛⬛⬛🏻⬛⬜⬜⬜<br>
⬜⬜⬜⬜⬛🏻⬛⬛⬛⬛⬛⬛🏻⬛⬜⬜⬜⬜<br>
⬜⬜⬜⬜⬜⬛🏻🏻🏻🏻🏻🏻⬛⬜⬜⬜⬜⬜<br>
⬜⬜⬛⬛⬛🟥⬛⬛⬛⬛⬛⬛🟥⬛⬛⬛⬜⬜<br>
⬜⬛🟥🟥🟥🟥🟦🟦🟥🟥🟦🟦🟥🟥🟥🟥⬛⬜<br>
⬛🟥⬛⬛🟥🟥🟨🟨🟥🟥🟨🟨🟥🟥⬛⬛🟥⬛<br>
⬜⬛⬜⬜⬛🟦🟨🟨🟦🟦🟨🟨🟦⬛⬜⬜⬛⬜<br>
⬛⬜⬜⬜⬜⬛🟦🟦🟦🟦🟦🟦⬛⬜⬜⬜⬜⬛<br>
⬛⬜⬜⬜⬜⬛🟦🟦🟦🟦🟦🟦⬛⬜⬜⬜⬜⬛<br>
⬛⬜⬜⬜⬛🟦🟦🟦🟦🟦🟦🟦🟦⬛⬜⬜⬜⬛<br>
⬜⬛⬛⬛🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦⬛⬛⬛⬜<br>
⬜⬜⬜⬛🟦🟦🟦⬛⬛⬛⬛🟦🟦🟦⬛⬜⬜⬜<br>
⬜⬜⬜⬛🟦🟦🟦⬛⬜⬜⬛🟦🟦🟦⬛⬜⬜⬜<br>
⬜⬜⬜⬛🟦🟦🟦⬛⬜⬜⬛🟦🟦🟦⬛⬜⬜⬜<br>
⬜⬜⬛🟫🟫🟫🟫⬛⬜⬜⬛🟫🟫🟫🟫⬛⬜⬜<br>
⬜⬛🟫🟫🟫🟫🟫⬛⬜⬜⬛🟫🟫🟫🟫🟫⬛⬜<br>
⬜⬛⬛⬛⬛⬛⬛⬛⬜⬜⬛⬛⬛⬛⬛⬛⬛⬜<br>
</p>
</center>
