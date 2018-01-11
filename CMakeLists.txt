cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Bishop.cpp
        Bishop.h
        Board.cpp
        Board.h
        chess.cpp
        chess.h
        Chessmen.cpp
        Chessmen.h
        King.cpp
        King.h
        Knight.cpp
        Knight.h
        Pawn.cpp
        Pawn.h
        Player.cpp
        Player.h
        Queen.cpp
        Queen.h
        Rook.cpp
        Rook.h)

add_executable(ex2 ${SOURCE_FILES})