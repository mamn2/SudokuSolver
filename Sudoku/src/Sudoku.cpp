//
//  Sudoko.cpp
//  Sudoku
//
//  Created by Mohamed Amn on 3/7/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include "Sudoku.hpp"


SudokuPuzzle::SudokuPuzzle(std::string& setPuzzle_s) : puzzle_s(setPuzzle_s) {
    SudokuStringToArray();
}

void inline SudokuPuzzle::SudokuStringToArray() {
    for (int i = 0; i < puzzle_a.size(); i++) {
        for (int j = 0; j < puzzle_a[i].size(); j++) {
            int stringIndex = (9 * i) + (j + 1) - 1;
            puzzle_a[i][j] = puzzle_s.at(stringIndex);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const SudokuPuzzle& sudoku) {
    
    os << "MY SUDOKO BOARD\n\n";
    
    for (int i = 0; i < sudoku.puzzle_a.size(); i++) {
        if (i != 0 && i % 3 == 0) {
            //Adds horizontal space between 3x3 blocks
            os << "\n";
        }
        for (int j = 0; j < sudoku.puzzle_a.size(); j++) {
            if (j != 0 && j % 3 == 0) {
                //Adds vertical space between 3x3 blocks
                os << " ";
            }
            
            if ((char) sudoku.puzzle_a[i][j] == '_') {
                os << "0 ";
            } else {
                os << (char) sudoku.puzzle_a[i][j] << " ";
            }
        }
        //Resets line after three 3x3 blocks
        os << "\n";
    }
    os << "\n";
    
    return os;
    
}

std::istream& operator>>(std::istream& is, const SudokuPuzzle& sudoku) {
    return is;
}
