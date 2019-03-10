//
//  main.cpp
//  Sudoku
//
//  Created by Mohamed Amn on 3/7/19.
//  Copyright © 2019 Mohamed Amn. All rights reserved.
//

#include <iostream>
#include "Sudoku.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string string("___8_5____3__6___7_9___38___4795_3______71_9____2__5__1____248___9____5______6___");
    SudokuPuzzle puzzle(string);
    std::cout<<puzzle;
    return 0;
}
