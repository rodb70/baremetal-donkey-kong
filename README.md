# DonkeyKong
Gameboy Advance Donkey Kong Game - Created for CS 2110 at Georgia Institute of Technology
Modified by yours-truly
 
## Source Code

Source code is found in the `src` folder. It requires special files and tools provided in CS 2110 to compile.

Clone directory.</br>
```git clone https://github.com/rodb70/baremetal-donkey-kong.git```</br>

Change directory.</br>
```cd baremetal-donkey-kong```</br>

Update git submodules
```git submodule update --init```

Removes all compiled files.</br>
```make clean```</br>

Compiles source code.</br>
```make CPU=host```</br>

## Executable
The host executable can be fond under build/donky-kong/host-debug/donky-kong it is built for Linux using SDL2 

## Game Instructions
The goal of this game is to leap over the barrels, climb the ladders, and to reach Donkey Kong and save the princess.</br>

**Keys on host:**</br>
A: Jump</br>
B: Pause</br>
Up Arrow: Climb </br>
Left Arrow: Move Left </br>
Right Arrow: Move Right </br>
Space: Return to Splash Screen (works on every screen)</br>
Enter: Start Game/Resume Game</br></br>


![Alt Text](https://github.com/tomonarifeehan/DonkeyKong/blob/master/img/final_game.gif)

# Historical
Readme parts from original project below
 
## src
Install​ GBA​ emulator​ and​ compiler​ toolchain.</br>
```sudo​ apt-get​ install​ gcc-arm-none-eabi```</br>
```sudo add-apt-repository ppa:tricksterguy87/ppa-gt-cs2110```</br>
```sudo apt-get update```</br>
```sudo​ apt-get​ install​ cs2110-vbam-sdl```</br>

## Executable

The executable donkey-kong.gba can be found in the `bin` folder. It can be run directly in any Game Boy Advance Emulator.

