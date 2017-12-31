# DonkeyKong
Gameboy Advance Donkey Kong Game - Created for CS 2110 at Georgia Institute of Technology

**Source Code**

Source code is found in the `src` directory. It requires special files and tools provided in CS 2110 to compile.

Installs ​ the​ ​ GBA​ ​ emulator​ ​ and​ ​ the​ ​ compiler​ ​ toolchain.</br>
```sudo​ apt-get​ install​ gcc-arm-none-eabi```</br>
```sudo​ apt-get​ install​ libnewlib-arm-none-eabi```</br>
```sudo​ apt-get​ install​ cs2110-vbam-sdl```</br>

Clone this directory.</br>
```git clone https://github.com/tomonarifeehan/DonkeyKong.git```</br>

Change into directory.</br>
```cd DonkeyKong\src```</br>

Removes all compiled files.</br>
```make clean```</br>

Runs Gameboy Emulator.</br>
```make vba```</br>

**Executable**

The executable donkey-kong.gba can be found in the `directory` folder. It can be run directly in any Game Boy Advance Emulator.

**Game Instructions**
The goal of this game is to leap over the barrels, climb the ladders, and to reach Donkey Kong and save the princess.</br>

<strong>Keys:</strong></br>
Z: Jump</br>
X: Pause</br>
Up Arrow: Climb </br>
Left Arrow: Move Left </br>
Right Arrow: Move Right </br>
Backspace: Return to Splash Screen (works on every screen)</br>
Start: Start Game/Resume Game</br></br>


![Alt Text](https://github.com/tomonarifeehan/DonkeyKong/blob/master/img/final_game.gif)