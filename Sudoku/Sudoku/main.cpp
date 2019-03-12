//
//  main.cpp
//  Sudoku
//
//  Created by Mohamed Amn on 3/7/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "Sudoku.hpp"

int main(int argc, const char * argv[]) {
    SudokuPuzzle sudokuPuzzle;
    sudokuPuzzle.SetPuzzleS("_7___1___6____________53______8___2__3__4716_4_____57_____1_75__6_52__4_3____9_86");
    sudokuPuzzle.SolvePuzzle();
    sudokuPuzzle.PrintToFile();
}
