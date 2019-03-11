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
    static std::vector<SudokuPuzzle> sudoku_games;
    
    explicit SudokuPuzzle();
    friend std::ostream& operator<<(std::ostream& outStream, const SudokuPuzzle& sudoku);
    friend std::istream& operator>>(std::istream& inStream, SudokuPuzzle& sudoku);
    void SetPuzzleS(const std::string setPuzzle_s);
private:
    void inline SudokuStringToArray();
};

#endif /* Sudoko_hpp */
