// Status: AC, 8ms, beats 100%

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j, k, s, t;
    int SIZE = 9;
    bool *row, *col, *square;
    row = (bool*) malloc(sizeof(bool)*SIZE);
    col = (bool*) malloc(sizeof(bool)*SIZE);
    square = (bool*) malloc(sizeof(bool)*SIZE);

    for(i = 0; i < SIZE; ++i) {
        row[i] = false;
        col[i] = false;
        square[i] = false;
    }

    for(i = 0; i < SIZE; ++i) {
        for(j = 0; j < SIZE; ++j) {
            // check the i-th row
            if(board[i][j] != '.') {
                if(row[board[i][j] - '1'] == true) {
                    printf("row check failed. At [%d, %d]\n", i+1, j+1);
                    return false;
                }
                else
                    row[board[i][j] - '1'] = true;
            }

            // check the i-th column
            if(board[j][i] != '.') {
                if(col[board[j][i] - '1'] == true) {
                    printf("row check failed. At [%d, %d]\n", i+1, j+1);
                    return false;
                }
                else
                    col[board[j][i] - '1'] = true;
                
            }

            // check all 3x3 sub-boxs
            if(i == 0 || i == 3 || i == 6) {
                if(j == 0 || j == 3 || j == 6) {
                    for(s = 0; s < 3; ++s) {
                        for(t = 0; t < 3; ++t) {
                            if(board[i+s][j+t] != '.') {
                                if(square[board[i+s][j+t] - '1'] == true) {
                                    printf("3*3 square check failed. At [%d, %d]\n", i+1, j+1);
                                    return false;
                                }
                                else
                                    square[board[i+s][j+t] - '1'] = true;
                                
                            }
                        }
                    }

                    for(k = 0; k < SIZE; ++k)
                        square[k] = false;

                }
            }
        }

        for(k = 0; k < SIZE; ++k) {
            row[k] = false;
            col[k] = false;
        }


    }

    return true;
}