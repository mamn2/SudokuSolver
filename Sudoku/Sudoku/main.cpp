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
    SudokuPuzzle sudokuPuzzle2;
    sudokuPuzzle2.SetPuzzleS("____9_____3____74261__3______8_______29147__845_____7__4_____6_5__6___3_____812__");
    sudokuPuzzle2.SolvePuzzle();
    std::string filepath = "/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/Solutions";
    PrintAllGames(filepath);
}
