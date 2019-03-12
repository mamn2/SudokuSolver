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
    std::array<std::array<char, 9>, 9> puzzle_a;
    
    explicit SudokuPuzzle();
    std::string PrettyPrint() const;
    friend std::ostream& operator<<(std::ostream& outStream, const SudokuPuzzle& sudoku);
    friend std::istream& operator>>(std::istream& inStream, SudokuPuzzle& sudoku);
    bool LoadPuzzles(std::string& filepath) const;
    void SetPuzzleS(const std::string setPuzzle_s);
    void PrintToFile(std::string filepath) const;
    
    bool SolvePuzzle();
    bool FindEmptyTile(int &row, int &column) const;
    bool PuzzleIsPossible(const int &row, const int &column, const int &tileNum) const;
    bool NumExistsInRow(const int &row, const int &checkNum) const;
    bool NumExistsInColumn(const int &column, const int &checkNum) const;
    bool NumExistsInBox(const int &boxRow, const int &boxColumn, const int &tileNum) const;
    
    
private:
    void inline SudokuStringToArray();
};

static std::vector<SudokuPuzzle*> sudoku_games;
std::vector<SudokuPuzzle*>& GetSudokuGames();
void PrintAllGames(const std::string filepath);

#endif /* Sudoko_hpp */
