# Cross platfrom SFML CMake project template
Skeleton project folder for crossplatform building SFML-project with CMake.Includes ImGui for easy GUI.

# Prerequisites

## Mac OS

1. Install command line tools `xcode-select --install`
 - <https://osxdaily.com/2014/02/12/install-command-line-tools-mac-os-x/>

2. Install brew `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
 - <https://brew.sh/>

3. Install CMake `brew install cmake` 
 - Run `cmake --version` to confirm that CMake works from commmand line, if not:
 - Make sure `/usr/local/bin` is in your `PATH`
`echo $PATH` should contain `/usr/local/bin`
 - <https://stackoverflow.com/questions/32185079/installing-cmake-with-home-brew>

5. Download and install VSCode
 - <https://code.visualstudio.com/>
 - Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (⇧⌘X).
  - (Optional) Install CMake language support <https://marketplace.visualstudio.com/items?itemName=twxs.cmake>

## Linux
- This guide is based on Ubuntu distributions

1. `sudo apt udpate`

2. Install GCC, make and other tools: `sudo apt install build-essential`

3. 5. Download and install VSCode
 - <https://code.visualstudio.com/docs/setup/linux>
 - Install the C/C++ extension for VS Code. You can install the C/C++ extension by searching for 'c++' in the Extensions view (⇧⌘X).
  - (Optional) Install CMake language support <https://marketplace.visualstudio.com/items?itemName=twxs.cmake>

4. Install SFML dependencies:
 - Note that this is only for linux, refer to <https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php>
 - freetype
 - x11
 - xrandr
 - udev
 - opengl
 - flac
 - flac
 - ogg
 - vorbis
 - vorbisenc
 - vorbisfile
 - openal
 - pthread

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
If you have renamed your project folder after building the project try this: 
- Delete everything inside of "build" folder. Do steps 5-7 again inside of empty "build" folder.

# ps
- https://github.com/lutrarutra/sfml_cmake_skeleton/
- Creator: lutrarutra
