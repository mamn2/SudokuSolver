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
    std::string puzzleString;
    std::array<std::array<char, 9>, 9> puzzleArray;
    
    //Constructor for class, adds instance to sudoku_games vector
    explicit SudokuPuzzle();
    
    //Returns a string which is a "pretty" version of the Sudoku Puzzle
    std::string PrettyPrint() const;
    
    //Overloads operator for output, outputs to file if specified, or console if not
    friend std::ostream& operator<<(std::ostream& outStream, const SudokuPuzzle& sudoku);
    
    //Overloads the input operator, asks user for spf filepath
    friend std::istream& operator>>(std::istream& inStream, SudokuPuzzle& sudoku);

    //Loads multiple puzzles from a filepath into SudokuPuzzle objects
    //Returns true only if filepath is a valid spf file
    static bool LoadPuzzles(std::string& filepath);
    
    //Setter for puzzleString
    void SetPuzzleString(const std::string SetPuzzleString);
    
    //Prints current state of the board
    void PrintToFile(std::string filepath) const;
    
    //Attempts to solve the given puzzle, returns true if puzzle is successfully solved, false otherwise
    bool SolvePuzzle();
    
    //Searches for an empty tile in the puzzle, return true if empty tile is found
    bool FindEmptyTile(int &row, int &column) const;
    
    //Returns true if the current puzzle is possible (doesn't violate any rules of the game)
    bool PuzzleIsPossible(const int &row, const int &column, const char &tileNum) const;
    
    //Returns true if the number being added already exists in the row
    bool NumExistsInRow(const int &row, const char &checkNum) const;
    
    //Returns true if the number being added already exists in the column
    bool NumExistsInColumn(const int &column, const char &checkNum) const;
    
    //Returns true if the number being added already exists in the box
    bool NumExistsInBox(const int &boxRow, const int &boxColumn, const char &tileNum) const;
    
    
private:
    //Converts the string into an array, called when the string is set
    void inline SudokuStringToArray();
};

//Contains a list of all the sudoku games added from a file
static std::vector<SudokuPuzzle*> sudokuGames;

//Gets the sudoku game from the Sudoku.cpp file
std::vector<SudokuPuzzle*>& GetSudokuGames();

//Prints all the games added from a file;
void PrintAllGames(const std::string& filepath);

//Solves all puzzles in sudokuGames
void SolveAllPuzzles();

//Deletes all puzzles in sudokuGames from heap
void DeleteAllPuzzles();

#endif /* Sudoko_hpp */
