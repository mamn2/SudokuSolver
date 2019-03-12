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

std::string SudokuPuzzle::PrettyPrint() const {
    
    std::string prettyPuzzle;
    prettyPuzzle += "NEW BOARD\n\n";
    
    for (int i = 0; i < puzzle_a.size(); i++) {
        if (i != 0 && i % 3 == 0) {
            //Adds horizontal space between 3x3 blocks
            prettyPuzzle += "\n";
        }
        for (int j = 0; j < puzzle_a.size(); j++) {
            if (j != 0 && j % 3 == 0) {
                //Adds vertical space between 3x3 blocks
                prettyPuzzle += " ";
            }
            
            if (puzzle_a[i][j] == '_') {
                prettyPuzzle += "0 ";
            } else {
                prettyPuzzle += puzzle_a[i][j];
                prettyPuzzle += " ";
            }
        }
        //Resets line after three 3x3 blocks
        prettyPuzzle += "\n";
    }
    prettyPuzzle += "\n";
    
    return prettyPuzzle;
    
}
    

std::ostream& operator<<(std::ostream& os, const SudokuPuzzle& sudoku) {
    
    return os << sudoku.PrettyPrint();
    
}

std::istream& operator>>(std::istream& inStream, SudokuPuzzle& sudoku) {
    
    std::string filepath;
    std::cout << "Enter a filepath: " << std::endl;
    std::cin >> filepath;
    sudoku.LoadPuzzles(filepath);
    return inStream;
    
}

bool SudokuPuzzle::LoadPuzzles(std::string &filepath) const {
    
    std::string line;
    std::ifstream my_file;
    my_file.open(filepath);
    
    //Clear the current list of games before appending new games
    sudoku_games.clear();
    
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
            sudoku_games.push_back(current_sudoku);
            i++;
        }
        my_file.close();
        std::cout << "Successfully loaded puzzles" << std::endl;
        return true;
    } else {
        std::cout << "Unable to open file" << std::endl;
        return false;
    }
    
}

void SudokuPuzzle::SetPuzzleS(const std::string setPuzzle_s) {
    if (setPuzzle_s.size() != 81) {
        return;
    }
    puzzle_s = setPuzzle_s;
    SudokuStringToArray();
}

//Gets the sudoku_games vector for this translation unit
std::vector<SudokuPuzzle>& GetSudokuGames() {
    return sudoku_games;
}

//Backtracking algorithm used to solve puzzle recursively
//For more on how backpacking algos work: https://www.geeksforgeeks.org/backtracking-introduction/
bool SudokuPuzzle::SolvePuzzle() {
    
    int currentRow = 0;
    int currentColumn = 0;
    
    //If there is no empty locations, we have completed our board.
    if (!FindEmptyTile(currentRow, currentColumn)) {
        return true;
    } else {
        for (char tileNum = '1'; tileNum <= '9'; tileNum++) {
            if (PuzzleIsPossible(currentRow, currentColumn, tileNum)) {
                puzzle_a[currentRow][currentColumn] = tileNum;
                
                //recursively checks if assigning tileNum solves the puzzle
                if (SolvePuzzle()) {
                    return true;
                } else {
                    //This is triggerred if it's not possible to solve the puzzle by making this assignment
                    puzzle_a[currentRow][currentColumn] = '_';
                }
            }
        }
    }
    return false;
    
}

bool SudokuPuzzle::PuzzleIsPossible(const int &row, const int &column, const int &tileNum) const {
    
    bool puzzleIsPossible = !NumExistsInRow(row, tileNum)
                         && !NumExistsInColumn(column, tileNum)
                         && !NumExistsInBox(row - row % 3, column - column % 3, tileNum)
                         && puzzle_a[row][column] == '_';
    
    return puzzleIsPossible;
    
}

bool SudokuPuzzle::FindEmptyTile(int &row, int &column) const {
    
    //remember that since we are passing by reference, incrementing here also changes acutal values
    for (row = 0; row < 9; row++) {
        for (column = 0; column < 9; column++) {
            if (puzzle_a[row][column] == '_') {
                return true;
            }
        }
    }
    
    return false;
    
}

bool SudokuPuzzle::NumExistsInRow(const int &row, const int &checkNum) const {
    
    for (int column = 0; column < 9; column++) {
        if (puzzle_a[row][column] == checkNum) {
            return true;
        }
    }
    
    return false;
    
}

bool SudokuPuzzle::NumExistsInColumn(const int &column, const int &checkNum) const {
    
    for (int row = 0; row < 9; row++) {
        if (puzzle_a[row][column] == checkNum) {
            return true;
        }
    }
    
    return false;
    
}

bool SudokuPuzzle::NumExistsInBox(const int &boxRow, const int &boxColumn, const int &tileNum) const {
    
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (puzzle_a[boxRow + row][boxColumn + column] == tileNum) {
                return true;
            }
        }
    }
    
    return false;
    
}

void SudokuPuzzle::PrintToFile() const {
    
    std::string filepath;
    std::cout << "Enter a filepath to print to: " << std::endl;
    std::cin >> filepath;
    std::ofstream myfile;
    
    myfile.open(filepath);
    if (myfile.is_open()) {
        myfile << PrettyPrint();
    }
    
}
