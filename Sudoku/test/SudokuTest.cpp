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

TEST_CASE("Pretty Print") {
    
    SECTION("Console") {
        SudokuPuzzle sudokuPuzzle;
        std::string examplePuzzle = "___8_5____3__6___7_9___38___4795_3______71_9____2__5__1____248___9____5______6___";
        sudokuPuzzle.SetPuzzleS(examplePuzzle);
        std::string prettyPuzzle = "NEW BOARD\n\n0 0 0  8 0 5  0 0 0 \n0 3 0  0 6 0  0 0 7 \n0 9 0  0 0 3  8 0 0 \n\n0 4 7  9 5 0  3 0 0 \n0 0 0  0 7 1  0 9 0 \n0 0 0  2 0 0  5 0 0 \n\n1 0 0  0 0 2  4 8 0 \n0 0 9  0 0 0  0 5 0 \n0 0 0  0 0 6  0 0 0 \n\n";
        REQUIRE(prettyPuzzle == sudokuPuzzle.PrettyPrint().str());
    }
    
    SECTION("Print to file") {
        
    }
    
}

TEST_CASE("Input Stream") {
    
    SECTION("Empty File") {
        SudokuPuzzle sudokuPuzzle;
        std::string fileName("/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/EmptyFile");
        sudokuPuzzle.LoadPuzzles(fileName);
        CHECK(sudoku_games.size() == 0);
    }
    
    SECTION("One game file") {
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
