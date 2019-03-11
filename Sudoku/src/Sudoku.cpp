//
//  Sudoko.cpp
//  Sudoku
//
//  Created by Mohamed Amn on 3/7/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include <fstream>
#include "Sudoku.hpp"

SudokuPuzzle::SudokuPuzzle() { }

void inline SudokuPuzzle::SudokuStringToArray() {
    for (int i = 0; i < puzzle_a.size(); i++) {
        for (int j = 0; j < puzzle_a[i].size(); j++) {
            int stringIndex = (9 * i) + (j + 1) - 1;
            puzzle_a[i][j] = puzzle_s.at(stringIndex);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const SudokuPuzzle& sudoku) {
    
    os << "NEW BOARD\n\n";
    
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

void SudokuPuzzle::SetPuzzleS(const std::string setPuzzle_s) {
    if (setPuzzle_s.size() != 81) {
        return;
    }
    puzzle_s = setPuzzle_s;
    SudokuStringToArray();
}

//Initializing static class member
std::vector<SudokuPuzzle> SudokuPuzzle::sudoku_games;

std::istream& operator>>(std::istream& is, SudokuPuzzle& sudoku) {
    
    std::string line;
    std::ifstream my_file;
    std::string filepath;
    std::cout << "Enter a filepath: " << std::endl;
    std::cin >> filepath;
    my_file.open(filepath);
    
    //Clear the current list of games before appending new games
    SudokuPuzzle::sudoku_games.clear();
    
    //Iterate through the list and convert into SudokuPuzzle objects.
    if (my_file.is_open())
    {
        int i = 0;
        //Gets all the subsequent lines in the file
        while (getline(my_file,line)) {
            if (line == "") {
                break;
            } else if (line == "#spf1.0") {
                continue;
            }
            SudokuPuzzle current_sudoku;
            current_sudoku.SetPuzzleS(line);
            SudokuPuzzle::sudoku_games.push_back(current_sudoku);
            std::cout << SudokuPuzzle::sudoku_games.at(i);
            i++;
        }
        my_file.close();
        
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
    
    return is;
}
