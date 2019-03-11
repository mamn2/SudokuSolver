//
//  Sudoko.hpp
//  Sudoku
//
//  Created by Mohamed Amn on 3/7/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#ifndef Sudoko_hpp
#define Sudoko_hpp

#include <stdio.h>
#include <string>
#include <array>
#include <vector>
#include <iostream>

class SudokuPuzzle {
public:
    std::string puzzle_s;
    std::array<std::array<int, 9>, 9> puzzle_a;
    
    explicit SudokuPuzzle();
    friend std::ostream& operator<<(std::ostream& outStream, const SudokuPuzzle& sudoku);
    friend std::istream& operator>>(std::istream& inStream, SudokuPuzzle& sudoku);
    bool LoadPuzzles(std::string& filepath) const;
    void SetPuzzleS(const std::string setPuzzle_s);
    
    bool SolvePuzzle(std::array<std::array<int, 9>, 9> puzzle);
    bool FindEmptyTile(std::array<std::array<int, 9>, 9> puzzle, int &row, int &column);
    bool PuzzleIsPossible(std::array<std::array<int, 9>, 9> puzzle, int row, int column, int tileNum);
    bool NumExistsInRow(std::array<std::array<int, 9>, 9> puzzle, int row, int checkNum);
    bool NumExistsInColumn(std::array<std::array<int, 9>, 9> puzzle, int column, int checkNum);
    
    
private:
    void inline SudokuStringToArray();
};

static std::vector<SudokuPuzzle> sudoku_games;
std::vector<SudokuPuzzle>& GetSudokuGames();

#endif /* Sudoko_hpp */
