//
//  SudokuTest.cpp
//  Sudoku
//
//  Created by Mohamed Amn on 3/10/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sudoku.hpp"

TEST_CASE("Output Stream") {
    
}

TEST_CASE("Input Stream") {
    
    SECTION("Empty File") {
        SudokuPuzzle sudokuPuzzle;
        std::string fileName("/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/EmptyFile");
        sudokuPuzzle.LoadPuzzles(fileName);
        CHECK(sudoku_games.size() == 0);
    }
    
    SECTION("One Game File") {
        SudokuPuzzle sudokuPuzzle;
        std::string fileName("/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/OneGame");
        sudokuPuzzle.LoadPuzzles(fileName);
        CHECK(GetSudokuGames().size() == 1);
    }
    
    SECTION("Multiple games file") {
        SudokuPuzzle sudokuPuzzle;
        std::string fileName("/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/MultipleGames");
        sudokuPuzzle.LoadPuzzles(fileName);
        CHECK(GetSudokuGames().size() == 3);
    }
    
    SECTION("Non-existent file") {
        SudokuPuzzle sudokuPuzzle;
        std::string fileName("Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/MultipleGames");
        CHECK(sudokuPuzzle.LoadPuzzles(fileName) == false);
    }
    
    SECTION("Random user input") {
        SudokuPuzzle sudokuPuzzle;
        std::string userInput("Game of thrones hypeee");
        CHECK(sudokuPuzzle.LoadPuzzles(userInput) == false);
    }
    
}

TEST_CASE("Horizontal Check") {
    
}

TEST_CASE("Vertical Check") {
    
}

TEST_CASE("Box Check") {
    
}

TEST_CASE("Game Win Check") {
    
}
