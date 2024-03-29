//
//  SudokuTest.cpp
//  Sudoku
//
//  Created by Mohamed Amn on 3/10/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include <fstream>
#include "catch.hpp"
#include "Sudoku.hpp"

TEST_CASE("File Input") {

    SECTION("Empty File") {
        std::string fileName("/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/EmptyFile");
        SudokuPuzzle::LoadPuzzles(fileName);
        CHECK(GetSudokuGames().size() == 0);
        DeleteAllPuzzles();
    }

    SECTION("One game file") {
        std::string fileName("/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/OneGame");
        SudokuPuzzle::LoadPuzzles(fileName);
        CHECK(GetSudokuGames().size() == 1);
        DeleteAllPuzzles();
    }

    SECTION("Multiple games file") {
        std::string fileName("/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/MultipleGames");
        SudokuPuzzle::LoadPuzzles(fileName);
        CHECK(GetSudokuGames().size() == 3);
        DeleteAllPuzzles();
    }

    SECTION("Non-existent file") {
        std::string fileName("Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/MultipleGames");
        CHECK(SudokuPuzzle::LoadPuzzles(fileName) == false);
    }

    SECTION("Random user input") {
        std::string userInput("Game of thrones hypeee");
        CHECK(SudokuPuzzle::LoadPuzzles(userInput) == false);
    }
    
    SECTION("Non-SPF File") {
        std::string fileName("Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/NonSPFFile");
        
        SECTION("LoadPuzzles returns false") {
            CHECK(SudokuPuzzle::LoadPuzzles(fileName) == false);
        }
        
        SECTION("Does not append to game vector") {
            CHECK(GetSudokuGames().size() == 0);
        }
    }

}

TEST_CASE("SolvePuzzle helper methods") {
    
    SudokuPuzzle sudokuPuzzle;
    std::string puzzleString = "_7___1___6____________53______8___2__3__4716_4_____57_____1_75__6_52__4_3____9886";
    sudokuPuzzle.SetPuzzleString(puzzleString);
    
    SECTION("Vertical Check") {
    
        SECTION("Returns true when num already exists") {
            CHECK(sudokuPuzzle.NumExistsInColumn(0, '6'));
        }
        
        SECTION("Returns false when num doesn't exist") {
            CHECK(sudokuPuzzle.NumExistsInColumn(1, '2') == false);
        }
        
    }

    SECTION("Box Check") {
        
        SECTION("Returns true when num already exists") {
            CHECK(sudokuPuzzle.NumExistsInBox(0, 0, '7'));
        }
        
        SECTION("Returns false when num doesn't exist") {
            CHECK(sudokuPuzzle.NumExistsInBox(0, 0, '5') == false);
        }
    
    }

    SECTION("Horizontal Check") {
        
        SECTION("Returns true when num already exists") {
            CHECK(sudokuPuzzle.NumExistsInColumn(1, '7'));
        }
        
        SECTION("Returns false when num doesn't exist") {
            CHECK(sudokuPuzzle.NumExistsInColumn(2, '3') == false);
        }
    
    }
    
    SECTION("PuzzleIsPossible() Check") {
        
        SECTION("Returns true if adding value is possible") {
            CHECK(sudokuPuzzle.PuzzleIsPossible(0, 0, 5));
        }
        
        SECTION("Returns false if adding value is not possible") {
            CHECK(sudokuPuzzle.PuzzleIsPossible(0, 0, 7));
        }
        
    }
    
}

TEST_CASE("SolvePuzzle") {
    
    SECTION("Solving unsolvable puzzle doesn't change state") {

        SudokuPuzzle unsolvablePuzzle;
        std::string unsolvablePuzzleS = "_7___1___6____________53______8___2__3__4716_4_____57_____1_75__6_52__4_3____9886";
        unsolvablePuzzle.SetPuzzleString(unsolvablePuzzleS);

        SudokuPuzzle unsolvablePuzzleCopy = unsolvablePuzzle;
        unsolvablePuzzleCopy.SolvePuzzle();

        bool arrayIsSame = true;

        for (int i = 0; i < unsolvablePuzzle.puzzleArray.size(); i++) {
            for (int j = 0; j < unsolvablePuzzle.puzzleArray[i].size(); j++) {
                if (unsolvablePuzzle.puzzleArray[i][j] != unsolvablePuzzleCopy.puzzleArray[i][j]) {
                    arrayIsSame = false;
                }
            }
        }
        
        CHECK(arrayIsSame);

        CHECK(unsolvablePuzzle.puzzleArray == unsolvablePuzzleCopy.puzzleArray);

    }
    
    SECTION("Solving a puzzle changes array to solution") {
        
        SudokuPuzzle solvablePuzzle;
        std::string solvablePuzzleS = "_7___1___6____________53______8___2__3__4716_4_____57_____1_75__6_52__4_3____9_86";
        solvablePuzzle.SetPuzzleString(solvablePuzzleS);
        
        SudokuPuzzle solvablePuzzleCopy = solvablePuzzle;
        
        solvablePuzzle.SolvePuzzle();

        std::array<std::array<char, 9>, 9> solutionArray = { {
            { '5', '7', '9', '6', '8', '1', '4', '3', '2' },
            { '6', '2', '3', '7', '9', '4', '8', '1', '5' },
            { '1', '8', '4', '2', '5', '3', '6', '9', '7' },
            { '7', '1', '6', '8', '3', '5', '9', '2', '4' },
            { '2', '3', '5', '9', '4', '7', '1' ,'6', '8' },
            { '4', '9', '8', '1', '6', '2', '5', '7', '3' },
            { '8', '4', '2', '3', '1', '6', '7', '5', '9' },
            { '9', '6', '7', '5', '2', '8', '3', '4', '1' },
            { '3', '5', '1', '4', '7', '9', '2', '8', '6' }
        } };
        
        bool arrayIsSame = true;
        
        for (int i = 0; i < solutionArray.size(); i++) {
            for (int j = 0; j < solutionArray[i].size(); j++) {
                if (solutionArray[i][j] != solvablePuzzle.puzzleArray[i][j]) {
                    arrayIsSame = false;
                }
            }
        }
        
        CHECK(arrayIsSame);
        
    }

}

TEST_CASE("Pretty Print") {
    
    SECTION("Pretty print original unsolved game") {
        SudokuPuzzle sudokuPuzzle;
        std::string examplePuzzle = "___8_5____3__6___7_9___38___4795_3______71_9____2__5__1____248___9____5______6___";
        sudokuPuzzle.SetPuzzleString(examplePuzzle);
        std::string prettyPuzzle = "NEW BOARD\n\n0 0 0  8 0 5  0 0 0 \n0 3 0  0 6 0  0 0 7 \n0 9 0  0 0 3  8 0 0 \n\n0 4 7  9 5 0  3 0 0 \n0 0 0  0 7 1  0 9 0 \n0 0 0  2 0 0  5 0 0 \n\n1 0 0  0 0 2  4 8 0 \n0 0 9  0 0 0  0 5 0 \n0 0 0  0 0 6  0 0 0 \n\n";
        REQUIRE(prettyPuzzle == sudokuPuzzle.PrettyPrint());
    }
    
    SECTION("Pretty print solution") {
        
        SudokuPuzzle sudokuPuzzle;
        std::string examplePuzzle = "_7___1___6____________53______8___2__3__4716_4_____57_____1_75__6_52__4_3____9_86";
        sudokuPuzzle.SetPuzzleString(examplePuzzle);
        sudokuPuzzle.SolvePuzzle();
        std::string solvedPuzzle = "NEW BOARD\n\n5 7 9  6 8 1  4 3 2 \n6 2 3  7 9 4  8 1 5 \n1 8 4  2 5 3  6 9 7 \n\n7 1 6  8 3 5  9 2 4 \n2 3 5  9 4 7  1 6 8 \n4 9 8  1 6 2  5 7 3 \n\n8 4 2  3 1 6  7 5 9 \n9 6 7  5 2 8  3 4 1 \n3 5 1  4 7 9  2 8 6 \n\n";
        CHECK(solvedPuzzle == sudokuPuzzle.PrettyPrint());
        
    }
    
    SECTION("Pretty print solution to file") {
        
        SudokuPuzzle sudokuPuzzle;
        std::string examplePuzzle = "_7___1___6____________53______8___2__3__4716_4_____57_____1_75__6_52__4_3____9_86";
        sudokuPuzzle.SetPuzzleString(examplePuzzle);
        sudokuPuzzle.SolvePuzzle();
        std::string filepath = "/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/Solutions";
        sudokuPuzzle.PrintToFile(filepath);
        
        std::ifstream myFile;
        std::string line;
        myFile.open(filepath);
        
        //goes to line 3 to check that line
        for (int i = 1; i <= 3; i++) {
            getline(myFile, line);
        }
        
        CHECK(line == "5 7 9  6 8 1  4 3 2 ");
        
    }
    
    SECTION("Pretty print multiple solutions to file") {
        
        std::string originalGamesFilepath = "/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/MultipleGames";
        SudokuPuzzle::LoadPuzzles(originalGamesFilepath);
        SolveAllPuzzles();
        
        std::string solutionsFilepath = "/Users/mohamedamn/Documents/sudoku-mamn2/Sudoku/Sudoku/Solutions";
        PrintAllGames(solutionsFilepath);
        
        DeleteAllPuzzles();

        std::ifstream myFile;
        std::string line;
        myFile.open(solutionsFilepath);
        
        //goes to line 3 to check that line
        for (int i = 1; i <= 31; i++) {
            getline(myFile, line);
        }
        
        //Checks line 31 (The last board in the game)
        CHECK(line == "3 4 6  9 5 7  1 2 8 ");
        
    }
    
}
