# File Viewer

This project allows to view files and navigate on the filesystem.

It uses [Qt 6](https://doc.qt.io/qt-6/)

## Getting started

1. First, if you don't have an environment variable `QT_CMAKE_PREFIX` with the value 'Qt/<version>/mingw_64/lib/cmake'
   or something similar that points to Qt cmake, then create it or replace `$ENV{QT_CMAKE_PREFIX}`
   from `set(CMAKE_PREFIX_PATH "$ENV{QT_CMAKE_PREFIX}")` on [CMakeList](CMakeLists.txt) with the location in your system. Remember to use "" quote marks and to
   use / instead of \