# Cross platfrom SFML + ImGUI project template 

Project template for cross platform SFML-project using CMake.
Includes VSCode configs to build & debug and ImGui for easy GUI.

Build easy OpenGL projects with GUI e.g. for algorithm visualisation: <https://www.youtube.com/watch?v=TYzOSeK_qxM>

# Prerequisites

## Mac OS

1. Install command line tools `xcode-select --install`
 - Refer to <https://osxdaily.com/2014/02/12/install-command-line-tools-mac-os-x/>

2. Install brew `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
 - Refer to <https://brew.sh/>

3. Install CMake `brew install cmake` 
 - Run `cmake --version` to confirm that CMake works from commmand line, if not:
 - Make sure `/usr/local/bin` is in your `PATH`
`echo $PATH` should contain `/usr/local/bin`
 - Refer to <https://stackoverflow.com/questions/32185079/installing-cmake-with-home-brew>

5. Download and install VSCode
 - <https://code.visualstudio.com/>
 - Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (⇧⌘X).
  - (Optional) Install CMake language support <https://marketplace.visualstudio.com/items?itemName=twxs.cmake>

## Linux
- This guide is based on Ubuntu distributions

1. `sudo apt udpate`

2. Install GCC, make and other tools: `sudo apt install build-essential`

3. Download and install VSCode
 - <https://code.visualstudio.com/docs/setup/linux>
 - Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (⇧⌘X).
  - (Optional) Install CMake language support <https://marketplace.visualstudio.com/items?itemName=twxs.cmake>

4. Install SFML dependencies:
 - Note that this is only for linux, refer to <https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php>
 - `sudo apt install libx11-dev xorg-dev freeglut3-dev libudev-dev`
 - Other dependencies might be required depending on your distribution, refer to the link above.

5. Install CMake
- `sudo apt install cmake`

## Windows
 - Guide based on: <https://code.visualstudio.com/docs/cpp/config-mingw>, refer to link if you encounter any errors

1. Download and install VSCode
 - <https://code.visualstudio.com/>
 - Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (⇧⌘X).
 <https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools>
 - (Optional) Install CMake language support <https://marketplace.visualstudio.com/items?itemName=twxs.cmake>

2. Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (⇧⌘X).

3. Download and install MSYS2
 - <https://www.msys2.org/>

4. Install MinGW C++ compiler with MSYS2
- After installation MSYS2 command line tool will open
- Run `pacman -Syu` in MSYS2 to update databse and packages
- Open MSYS2 again from start menu
- update rest of the base packages `pacman -Su`
- Install compiler `pacman -S --needed base-devel mingw-w64-x86_64-toolchain`

5. Add MinGW to windows PATH environment variable
- In the Windows search bar, type 'settings' to open your Windows Settings.
- Search for Edit environment variables for your account.
- Choose the Path variable and then select Edit.
- Select New and add the Mingw-w64 destination folder path to the system path. The exact path depends on which version of Mingw-w64 you have installed and where you installed it. If you used the settings above to install Mingw-w64, then add this to the path: C:\msys64\mingw64\bin.
- Select OK to save the updated PATH. You will need to reopen any console windows for the new PATH location to be available.

6. Check your MinGW installation
- open CMD and run `g++ --version` and `gdb --version`

7. Download and install CMake
- Enable option to add CMake to PATH environment variable during installation.
- https://cmake.org/install/

# How to build?

#### You need CMake. Install it for command line atleast. If you are not sure if you have it: `cmake --version`
#### After installing CMake  follow steps 1-7
1. Clone project or download Zip-file and unzip it
2. Open terminal inside of the project
3. `mkdir build` -  to make "build" directory inside of project folder
4. `cd ./build` - go inside of "build" folder
5. `cmake ..` - to link files (On windows use command `cmake .. -G "MinGW Makefiles` if you followed windows prerequisites guide)
6. `make` - to build project (On windows use command `mingw32-make.exe` if you followed windows prerequisites guide)
7. `./a` - to display output

# How to use?

#### If you are new to CMake don't worry so am I. I made this template for myself so it will be easy to copy this for new project and be ready to go without additional hassle.
- In project folder you will find "CMakeLists.txt". Don't rename it and don't move it if you don't know what you are doing.
- Add your ".cpp"-files here: `set(SOURCES src/main.cpp 'here')`. Don't forget "`src/`".
- Create your header files (".h/.hpp")-files inside of src folder. If you want to put them into different folder just modify this line: `include_directories(your_include_folder_name)`
- If your project uses additional files like images or fonts keep them in "res" folder. and add this line for each additional file `configure_file(res/filename.extension filename.extension COPYONLY)`

# Not working?
If you have renamed your project folder after generating makefiles with CMake or run misconfigured CMake try this: 
- Delete everything inside of "build" folder. Do steps 5-7 again inside of empty "build" folder.

# 3rd party libraries

## SFML
- SFML: SFML is a simple, fast, cross-platform and object-oriented multimedia API
- <https://github.com/SFML/SFML>

## Dear ImGui
- ImGui: Dear ImGui is a bloat-free graphical user interface library for C++.
- <https://github.com/ocornut/imgui>

## ImGui-SFML binding
- ImGui-SFML: Library which allows you to use Dear ImGui with SFML binding 
- <https://github.com/eliasdaler/imgui-sfml>

# p.s.
- https://github.com/lutrarutra/SFML-Project-Template
- Creator: lutrarutra
