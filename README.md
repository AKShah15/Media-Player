# C++ Learning Project

This repository contains various C++ programs demonstrating fundamental concepts and includes a mini media player project.

## Project Structure

### Basic Concepts
- [tut1.cpp](tut1.cpp) - Hello World program
- [CommentAndVariables.cpp](CommentAndVariables.cpp) - Comments and basic variables
- [datatypes.cpp](datatypes.cpp) - Different data types in C++
- [BasicInputAndOutput.cpp](BasicInputAndOutput.cpp) - Input/Output operations

### Object-Oriented Programming
- [ClassPrivatePublic.cpp](ClassPrivatePublic.cpp) - Classes, public and private access modifiers
- [FriendFunction.cpp](FriendFunction.cpp) - Friend functions demonstration
- [FunctionOverloading.cpp](FunctionOverloading.cpp) - Function overloading examples

### Advanced Concepts
- [ReferanceAndTypecasting.cpp](ReferanceAndTypecasting.cpp) - References and type conversion

### Mini Project
- [MiniProjectMediaPlayer.cpp](MiniProjectMediaPlayer.cpp) - A console-based media player implementation featuring:
  - Object-oriented design with inheritance
  - Audio and video file handling
  - Playlist management
  - Basic media controls (play, pause, stop)

## Building and Running

To compile any program, use a C++ compiler like g++:

```bash
g++ programname.cpp -o programname
```

For the media player project:
```bash
g++ MiniProjectMediaPlayer.cpp -o mediaplayer -lwinmm
```

## Requirements

- C++ compiler (GCC/G++ recommended)
- Windows OS (for media player functionality)
- winmm.lib (Windows Multimedia Library)

## Features

- Basic C++ syntax demonstrations
- Object-oriented programming concepts
- File handling
- Media playback functionality
- Console-based user interface
