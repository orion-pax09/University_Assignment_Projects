//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//using namespace sf;
//using namespace std;
//bool validBishopMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd);
//bool validKnightMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd);
//bool ValidRookMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd);
//bool ValidPawnMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd);
//bool ValidQueenMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd);
//bool isKingInCheck(int board[8][8], bool WhiteKing);
//bool validKingMove(int board[8][8], int rowSart, int colStart, int rowEnd, int colEnd);
//bool isMoveLegal(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd, bool whiteTurn);
//bool isPawnPromotion(int Piece, int rowEnd);
//void PromotePawn(int board[8][8], int row, int col, int choice);
//bool ValidEnPassantMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd, bool whiteturn, int epRow, int epCol);
//bool ValidCastlingMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd, bool whiteTurn, bool kingMoved, bool rookLeftMoved, bool rookRightMoved);
//bool isCheckmate(int board[8][8], bool whiteTurn);
//int TILE_SIZE = 80;
//
//const int EMPTY = 0;
//const int WPAWN = 1;
//const int WROOK = 2;
//const int WKNIGHT = 3;
//const int WBISHOP = 4;
//const int WQUEEN = 5;
//const int WKING = 6;
//
//const int BPAWN = -1;
//const int BROOK = -2;
//const int BKNIGHT = -3;
//const int BBISHOP = -4;
//const int BQUEEN = -5;
//const int BKING = -6;
//
//int BOARD_OFFSET_Y = 20;
//
//
//int main() {
//    int selectedRow = -1;
//    int selectedCol = -1;
//    bool pieceSelected = false;
//    bool whiteTurn = true; // Added: track whose turn it is
//
//
//    bool promotionActive = false;
//    int promoRow = -1;
//    int promoCol = -1;
//    int promoPawn = EMPTY;
//
//    Sprite sprites[4];
//    bool promoSpritesReady = false;
//
//    bool enPassantAvailable = false;
//    int enPassantRow = -1;
//    int enPassantCol = -1;
//
//
//    int whiteKingMoved = false;
//    int blackKingMoved = false;
//
//    int whiteRookLeftMoved = false;
//    int whiteRookRightMoved = false;
//
//    int blackRookLeftMoved = false;
//    int blackRookRightMoved = false;
//
//    bool gameOver = false;
//    bool whiteWon = false;
//
//
//
//    RenderWindow window(VideoMode(640, 680), "My Chess Game");
//
//    RectangleShape tile;
//    tile.setSize(Vector2f(TILE_SIZE, TILE_SIZE));
//
//    Texture textures[13];
//
//    textures[WPAWN + 6].loadFromFile("images/wp.png");
//    textures[WROOK + 6].loadFromFile("images/wr.png");
//    textures[WKNIGHT + 6].loadFromFile("images/wn.png");
//    textures[WBISHOP + 6].loadFromFile("images/wb.png");
//    textures[WQUEEN + 6].loadFromFile("images/wq.png");
//    textures[WKING + 6].loadFromFile("images/wk.png");
//
//    textures[BPAWN + 6].loadFromFile("images/bp.png");
//    textures[BROOK + 6].loadFromFile("images/br.png");
//    textures[BKNIGHT + 6].loadFromFile("images/bn.png");
//    textures[BBISHOP + 6].loadFromFile("images/bb.png");
//    textures[BQUEEN + 6].loadFromFile("images/bq.png");
//    textures[BKING + 6].loadFromFile("images/bk.png");
//
//    int board[8][8] =
//    {
//        { BROOK, BKNIGHT, BBISHOP, BQUEEN, BKING, BBISHOP, BKNIGHT, BROOK },
//        { BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN, BPAWN },
//        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
//        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
//        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
//        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
//        { WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN, WPAWN },
//        { WROOK, WKNIGHT, WBISHOP, WQUEEN, WKING, WBISHOP, WKNIGHT, WROOK }
//    };
//
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed)
//                window.close();
//
//            if (!gameOver  && event.type == Event::MouseButtonPressed &&
//                event.mouseButton.button == Mouse::Left) {
//
//                
//
//                int mouseX = event.mouseButton.x;
//                int mouseY = event.mouseButton.y;
//
//                int col = mouseX / TILE_SIZE;
//                int row = (mouseY - BOARD_OFFSET_Y) / TILE_SIZE;
//
//                if (row >= 0 && row < 8 && col >= 0 && col < 8) {
//                    // If no piece is selected yet
//                    if (!pieceSelected) {
//                        int piece = board[row][col];
//
//                        // Check if it's white's turn and clicking a white piece
//                        if (whiteTurn && piece > 0) { // White pieces are positive
//                            selectedRow = row;
//                            selectedCol = col;
//                            pieceSelected = true;
//                        }
//                        // Check if it's black's turn and clicking a black piece
//                        else if (!whiteTurn && piece < 0) { // Black pieces are negative
//                            selectedRow = row;
//                            selectedCol = col;
//                            pieceSelected = true;
//                        }
//                    }
//                    // If a piece is already selected
//                    else if (pieceSelected) {
//                        // Check if destination is empty or contains opponent's piece
//                        bool validMove = false;
//
//                        if (abs(board[selectedRow][selectedCol]) == WBISHOP) {
//                            validMove = validBishopMove(board, selectedRow, selectedCol, row, col);
//
//                        }
//                        else if (abs(board[selectedRow][selectedCol]) == WKNIGHT) {
//                            validMove = validKnightMove(board, selectedRow, selectedCol, row, col);
//                        }
//                        else if (abs(board[selectedRow][selectedCol]) == WROOK) {
//                            validMove = ValidRookMove(board, selectedRow, selectedCol, row, col);
//                        }
//                        else if (abs(board[selectedRow][selectedCol]) == WPAWN) {
//
//                            validMove = ValidPawnMove(board, selectedRow, selectedCol, row, col);
//
//                            if (!validMove && enPassantAvailable) {
//                                validMove = ValidEnPassantMove(board, selectedRow, selectedCol, row, col, whiteTurn, enPassantRow, enPassantCol);
//
//                            }
//
//                        }
//                        else if (abs(board[selectedRow][selectedCol]) == WQUEEN) {
//                            validMove = ValidQueenMove(board, selectedRow, selectedCol, row, col);
//                        }
//                        else if (abs(board[selectedRow][selectedCol]) == WKING) {
//                            validMove = validKingMove(board, selectedRow, selectedCol, row, col);
//
//                            if (!validMove) {
//
//                                if (whiteTurn) {
//                                    
//                                    validMove = ValidCastlingMove(board, selectedRow, selectedCol, row, col, whiteTurn, whiteKingMoved, whiteRookLeftMoved, whiteRookRightMoved);
//                                }
//                                else {
//                                    validMove = ValidCastlingMove(board, selectedRow, selectedCol, row, col, whiteTurn, blackKingMoved, blackRookLeftMoved, blackRookRightMoved);
//                                }
//                                
//                            }
//                        }
//                        else {
//                            if (whiteTurn) {
//                                // White can move to empty squares or capture black pieces
//                                if (board[row][col] <= 0) { // Empty (0) or black piece (< 0)
//                                    validMove = true;
//                                }
//                            }
//                            else {
//                                // Black can move to empty squares or capture white pieces
//                                if (board[row][col] >= 0) { // Empty (0) or white piece (> 0)
//                                    validMove = true;
//                                }
//                            }
//
//                        }
//
//
//
//                        if (validMove && isMoveLegal(board, selectedRow, selectedCol, row, col, whiteTurn)) {
//
//                            int movedPiece = board[selectedRow][selectedCol];
//
//                            if (abs(movedPiece) == WPAWN && enPassantAvailable && row == enPassantRow && col == enPassantCol) {
//                                if (whiteTurn) {
//                                    board[row + 1][col] = EMPTY;
//                                }
//                                else {
//                                    board[row - 1][col] = EMPTY;
//                                }
//                            }
//
//                            if (abs(movedPiece) == WKING && abs(col - selectedCol) == 2) {
//                                if (col > selectedCol) {
//                                    board[row][col - 1] = board[row][7];
//                                    board[row][7] = EMPTY;
//                                }
//                                else {
//                                    board[row][col + 1] = board[row][0];
//                                    board[row][0] = EMPTY;
//                                }
//                            }
//
//                            // Move the piece
//                            board[row][col] = board[selectedRow][selectedCol];
//                            board[selectedRow][selectedCol] = EMPTY;
//
//
//                            // King moved
//                            if (movedPiece == WKING) whiteKingMoved = true;
//                            if (movedPiece == BKING) blackKingMoved = true;
//
//                            // Rooks moved
//                            if (movedPiece == WROOK && selectedCol == 0) whiteRookLeftMoved = true;
//                            if (movedPiece == WROOK && selectedCol == 7) whiteRookRightMoved = true;
//
//                            if (movedPiece == BROOK && selectedCol == 0) blackRookLeftMoved = true;
//                            if (movedPiece == BROOK && selectedCol == 7) blackRookRightMoved = true;
//
//
//
//                            enPassantAvailable = false;
//
//                            if (abs(movedPiece) == WPAWN && abs(row - selectedRow) == 2) {
//                                enPassantAvailable = true;
//                                enPassantRow = (row + selectedRow) / 2;
//                                enPassantCol = col;
//                            }
//
//                            
//
//                            if (abs(movedPiece) == WPAWN && isPawnPromotion(movedPiece, row)) {
//                                promotionActive = true;
//                                promoRow = row;
//                                promoCol = col;
//                                promoPawn = movedPiece;
//                            }
//                            
//                                // Switch turns
//                                whiteTurn = !whiteTurn;
//
//                                // 🔥 CHECK FOR CHECKMATE
//                                if (isCheckmate(board, whiteTurn)) {
//                                    gameOver = true;
//                                    whiteWon = !whiteTurn; // previous player wins
//                                }
//
//                            
//                            
//
//                            
//
//                           
//
//                        }
//
//                        // Deselect the piece regardless of move validity
//                        selectedRow = -1;
//                        selectedCol = -1;
//                        pieceSelected = false;
//                    }
//
//                    
//
//                }
//            }
//        }
//
//        window.clear();
//
//        // Draw chessboard and pieces
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                tile.setPosition(
//                    j * TILE_SIZE,
//                    i * TILE_SIZE + BOARD_OFFSET_Y
//                );
//
//                if (i == selectedRow && j == selectedCol) {
//                    tile.setFillColor(Color(186, 202, 68)); // Highlight selected square
//                }
//                else {
//                    tile.setFillColor((i + j) % 2
//                        ? Color(118, 150, 86)
//                        : Color(238, 238, 210));
//                }
//
//                window.draw(tile);
//
//
//
//
//                // Draw piece if present
//                int piece = board[i][j];
//                if (piece != EMPTY) {
//                    Sprite sprite;
//                    sprite.setTexture(textures[piece + 6]);
//
//                    FloatRect bounds = sprite.getLocalBounds();
//
//                    float scale = TILE_SIZE / max(bounds.width, bounds.height);
//                    sprite.setScale(scale, scale);
//
//                    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
//
//                    sprite.setPosition(
//                        j * TILE_SIZE + TILE_SIZE / 2,
//                        i * TILE_SIZE + TILE_SIZE / 2 + BOARD_OFFSET_Y
//                    );
//
//                    window.draw(sprite);
//                }
//
//               
//
//
//            }
//        }
//
//        Font font;
//        font.loadFromFile("ARIAL.TTF");
//        
//
//        if (gameOver) {
//
//            RectangleShape overlay;
//            overlay.setSize(Vector2f(640, 680));
//            overlay.setFillColor(Color(0, 0, 0, 180));
//            window.draw(overlay);
//
//            Text text;
//            text.setFont(font);
//            text.setCharacterSize(48);
//            text.setFillColor(Color::White);
//            text.setStyle(Text::Bold);
//
//            if (whiteWon)
//                text.setString("CHECKMATE!\nWHITE WINS");
//            else
//                text.setString("CHECKMATE!\nBLACK WINS");
//
//            FloatRect bounds = text.getLocalBounds();
//            text.setOrigin(bounds.width / 2, bounds.height / 2);
//            text.setPosition(320, 340);
//
//            window.draw(text);
//        }
//
//
//        window.display();
//    }
//
//    return 0;
//}
//
//
//bool validBishopMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd) {
//    int rowDiff = abs(rowEnd - rowStart);
//    int colDiff = abs(colEnd - colStart);
//
//    if (rowDiff != colDiff) {
//        return false;
//    }
//
//    int rowStep = rowEnd > rowStart ? 1 : -1;
//    int colStep = colEnd > colStart ? 1 : -1;
//
//
//    int r = rowStart + rowStep;
//    int c = colStart + colStep;
//
//    while (r != rowEnd && c != colEnd) {
//        if (board[r][c] != EMPTY) {
//            return false;
//        }
//
//        r += rowStep;
//        c += colStep;
//
//
//
//    }
//
//    if (board[rowStart][colStart] > 0 && board[rowEnd][colEnd] > 0) {
//        return false;
//    }
//    else if (board[rowStart][colStart] < 0 && board[rowEnd][colEnd] < 0) {
//        return false;
//    }
//
//    return true;
//
//}
//
//
//
//bool validKnightMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd) {
//    int rowDifference = abs(rowEnd - rowStart);
//    int colDifference = abs(colEnd - colStart);
//
//    if (!((rowDifference == 2 && colDifference == 1) || (rowDifference == 1 && colDifference == 2))) {
//        return false;
//    }
//
//    if (board[rowStart][colStart] > 0 && board[rowEnd][colEnd]>0) {
//        return false;
//    }
//
//    if (board[rowStart][colStart] < 0 && board[rowEnd][colEnd] < 0) {
//        return false;
//    }
//
//    return true;
//}
//
//
//
//bool ValidRookMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd) {
//    if (rowStart != rowEnd && colStart != colEnd) {
//        return false;
//    }
//
//    int rowStep = 0;
//    int colStep = 0;
//
//    if (rowEnd > rowStart) {
//        rowStep = 1;
//    }
//    else if (rowEnd < rowStart) {
//        rowStep = -1;
//    }
//
//
//    if (colEnd > colStart) {
//        colStep = 1;
//    }
//    else if (colEnd < colStart) {
//        colStep = -1;
//    }
//
//    int r = rowStart + rowStep;
//    int c = colStart + colStep;
//
//    while (r != rowEnd || c != colEnd) {
//
//
//        if (board[r][c] != EMPTY) {
//            return false;
//        }
//
//        r += rowStep;
//        c += colStep;
//
//    }
//
//    if (board[rowStart][colStart] > 0 && board[rowEnd][colEnd] > 0) {
//        return false;
//    }
//
//    if (board[rowStart][colStart] < 0 && board[rowEnd][colEnd] < 0) {
//        return false;
//    }
//
//    return true;
//
//}
//
//
//bool ValidPawnMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd) {
//    int piece = board[rowStart][colStart];
//
//    if (piece == WPAWN) {
//        if (colStart == colEnd &&
//            (rowStart == rowEnd + 1) &&
//            board[rowEnd][colEnd] == EMPTY) {
//            return true;
//        }
//
//        if (colStart == colEnd && rowStart == 6 && board[rowStart - 1][colStart] == EMPTY && board[rowEnd][colEnd] == EMPTY && rowStart == rowEnd + 2) {
//            return true;
//        }
//
//        if (abs(colEnd - colStart) == 1 &&
//            rowEnd == rowStart - 1 &&
//            board[rowEnd][colEnd] < 0) {
//            return true;
//        }
//    }
//    else if (piece == BPAWN) {
//        if (colStart == colEnd && rowStart == rowEnd - 1 && board[rowEnd][colEnd] == EMPTY) {
//            return true;
//        }
//
//        if (colStart == colEnd && rowStart == 1 && board[rowStart + 1][colStart] == EMPTY && board[rowEnd][colEnd] == EMPTY && rowStart == rowEnd - 2) {
//            return true;
//        }
//
//        if (abs(colEnd - colStart) == 1 && rowEnd == rowStart + 1 && board[rowEnd][colEnd] > 0) {
//            return true;
//        }
//    }
//
//    return false;
//
//}
//
//
//
//
//
//bool ValidQueenMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd) {
//    if (validBishopMove(board, rowStart, colStart, rowEnd, colEnd) || ValidRookMove(board, rowStart, colStart, rowEnd, colEnd)) {
//        return true;
//    }
//
//    return false;
//}
//
//
//bool SquareUnderAttack(int board[8][8], int targetRow, int targetCol, bool bywhite) {
//
//    for (int r = 0; r < 8; r++) {
//        for (int c = 0; c < 8; c++) {
//
//            int piece = board[r][c];
//
//            if (piece == EMPTY) {
//                continue;
//            }
//
//            if (bywhite && piece < 0) {
//                continue;
//            }
//
//            if (!bywhite && piece > 0) {
//                continue;
//            }
//
//
//            // check for pawn attack
//
//            if (abs(piece) == WPAWN) {
//                if (bywhite) {
//                    if (targetRow == r - 1 && abs(targetCol - c) == 1) {
//                        return true;
//                    }
//                }
//                else {
//                    if (targetRow == r + 1 && abs(targetCol - c) == 1) {
//                        return true;
//                    }
//                }
//            }
//            else if (abs(piece) == WKNIGHT) {
//                int rowStep = abs(targetRow - r);
//                int colStep = abs(targetCol - c);
//
//                if ((rowStep == 2 && colStep == 1) || (rowStep == 1 && colStep == 2)) {
//                    return true;
//                }
//            }
//            else if (abs(piece) == WBISHOP) {
//                if (validBishopMove(board, r, c, targetRow, targetCol)) {
//                    return true;
//                }
//            }
//            else if (abs(piece) == WROOK) {
//                if (ValidRookMove(board, r, c, targetRow, targetCol)) {
//                    return true;
//                }
//            }
//            else if (abs(piece) == WQUEEN) {
//                if (ValidQueenMove(board, r, c, targetRow, targetCol)) {
//                    return true;
//                }
//            }
//            else if (abs(piece) == WKING) {
//                if (abs(targetRow - r) <= 1 && abs(targetCol - c) <= 1) {
//                    return true;
//                }
//            }
//        }
//    }
//
//    return false;
//}
//
//
//
//bool isKingInCheck(int board[8][8], bool WhiteKing) {
//
//    int kingrow = -1;
//    int kingcol = -1;
//
//    for (int r = 0; r < 8; r++) {
//        for (int c = 0; c < 8; c++) {
//            if (WhiteKing && board[r][c] == WKING) {
//                kingrow = r;
//                kingcol = c;
//            }
//            else if (!WhiteKing && board[r][c] == BKING) {
//                kingrow = r;
//                kingcol = c;
//            }
//        }
//    }
//
//    if (kingrow == -1) {
//        return false;
//    }
//
//    if (WhiteKing) {
//        return SquareUnderAttack(board, kingrow, kingcol, false);
//    }
//    else {
//        return SquareUnderAttack(board, kingrow, kingcol, true);
//    }
//
//}
//
//
//bool validKingMove(int board[8][8], int rowSart, int colStart, int rowEnd, int colEnd) {
//
//    int piece = board[rowSart][colStart];
//
//    if (rowSart == rowEnd && colStart == colEnd) {
//        return false;
//    }
//
//    if (abs(rowEnd - rowSart) > 1 || abs(colEnd - colStart) > 1) {
//        return false;
//    }
//
//    if (piece > 0 && board[rowEnd][colEnd] > 0) {
//        return false;
//    }
//
//    if (piece < 0 && board[rowEnd][colEnd] < 0) {
//        return false;
//    }
//
//
//    int temp = board[rowEnd][colEnd];
//    board[rowEnd][colEnd] = piece;
//    board[rowSart][colStart] = EMPTY;
//
//    bool incheck;
//
//    if (piece > 0) {
//        incheck = isKingInCheck(board, true);
//    }
//    else {
//        incheck = isKingInCheck(board, false);
//    }
//
//
//    board[rowSart][colStart] = piece;
//    board[rowEnd][colEnd] = temp;
//
//    if (incheck) {
//        return false;
//    }
//
//    return true;
//}
//
//
//bool isMoveLegal(int board[8][8],int rowStart, int colStart,int rowEnd, int colEnd,bool whiteTurn)
//{
//    int piece = board[rowStart][colStart];
//    int captured = board[rowEnd][colEnd];
//
//    // 1. Make the move TEMPORARILY
//    board[rowEnd][colEnd] = piece;
//    board[rowStart][colStart] = EMPTY;
//
//    // 2. Check if king is still in check
//    bool stillInCheck = isKingInCheck(board, whiteTurn);
//
//    // 3. Undo the move
//    board[rowStart][colStart] = piece;
//    board[rowEnd][colEnd] = captured;
//
//    // 4. If king still in check → illegal move
//    return !stillInCheck;
//}
//
//
//bool isPawnPromotion(int Piece, int rowEnd) {
//    if (Piece == WPAWN && rowEnd == 0) {
//        return true;
//    }
//
//    if (Piece == BPAWN && rowEnd == 7) {
//        return true;
//    }
//
//    return false;
//}
//
//
//void PromotePawn(int board[8][8], int row, int col, int choice) {
//
//    // 1 = QUEEN , 2 = ROOK , 3 = BISHOP, 4 = KNIGHT
//
//    if (board[row][col] > 0) {
//        if (choice == 1) {
//            board[row][col] = WQUEEN;
//        }
//        else if (choice == 2) {
//            board[row][col] = WROOK;
//        }
//        else if (choice == 3) {
//            board[row][col] == WBISHOP;
//        }
//        else if (choice == 4) {
//            board[row][col] == WKNIGHT;
//        }
//    }
//    else {
//        if (choice == 1) {
//            board[row][col] == BQUEEN;
//        }
//        else if (choice == 2) {
//            board[row][col] == BROOK;
//        }
//        else if (choice == 3) {
//            board[row][col] == BBISHOP;
//        }
//        else if (choice == 4) {
//            board[row][col] == BKNIGHT;
//        }
//    }
//}
//
//
//bool ValidEnPassantMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd, bool whiteturn, int epRow, int epCol) {
//
//    int piece = board[rowStart][colStart];
//
//    if (abs(piece) != WPAWN) {
//        return false;
//    }
//
//    if (rowEnd != epRow || colEnd != epCol) {
//        return false;
//    }
//
//    if (whiteturn && piece == WPAWN) {
//        if (rowStart == epRow + 1 && abs(colStart - epCol) == 1) {
//            return true;
//        }
//    }
//
//    if (whiteturn && piece == BPAWN) {
//        if (rowStart == epRow - 1 && abs(colStart - epCol) == 1) {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//
//bool ValidCastlingMove(int board[8][8], int rowStart, int colStart, int rowEnd, int colEnd, bool whiteTurn, bool kingMoved, bool rookLeftMoved, bool rookRightMoved ) {
//
//    int piece = board[rowStart][colStart];
//
//    if (abs(piece) != WKING) {
//        return false;
//    }
//
//    if (kingMoved) {
//        return false;
//    }
//
//    if (rowStart != rowEnd) {
//        return false;
//    }
//
//    int colDiff = colEnd - colStart;
//    if (abs(colDiff) != 2) {
//        return false;
//    }
//
//    if (isKingInCheck(board, whiteTurn)) {
//        return false;
//    }
//
//    if (colDiff == 2) {
//        if (rookRightMoved) {
//            return false;
//        }
//
//        if (board[rowStart][colStart + 1] != EMPTY || board[rowStart][colStart + 2] != EMPTY) {
//            return false;
//        }
//
//        if (SquareUnderAttack(board, rowStart, colStart + 1, !whiteTurn) || SquareUnderAttack(board, rowStart, colStart + 2, !whiteTurn)) {
//            return false;
//        }
//
//
//        return true;
//    }
//
//    if (colDiff == -2) {
//        if (rookLeftMoved) {
//            return false;
//        }
//
//        if (board[rowStart][colStart - 1] != EMPTY || board[rowStart][colStart - 2] != EMPTY || board[rowStart][colStart - 3] != EMPTY) {
//            return false;
//        }
//
//        if (SquareUnderAttack(board, rowStart, colStart - 1, !whiteTurn) || SquareUnderAttack(board, rowStart, colStart - 2, !whiteTurn)) {
//            return false;
//        }
//
//        return true;
//    }
//
//    return false;
//
//}
//
//
//bool isCheckmate(int board[8][8], bool whiteTurn) {
//
//    // If king is NOT in check → cannot be checkmate
//    if (!isKingInCheck(board, whiteTurn))
//        return false;
//
//    // Try EVERY possible move for current player
//    for (int r1 = 0; r1 < 8; r1++) {
//        for (int c1 = 0; c1 < 8; c1++) {
//
//            int piece = board[r1][c1];
//            if (piece == EMPTY)
//                continue;
//
//            // Skip opponent pieces
//            if (whiteTurn && piece < 0) continue;
//            if (!whiteTurn && piece > 0) continue;
//
//            // Try moving this piece to every square
//            for (int r2 = 0; r2 < 8; r2++) {
//                for (int c2 = 0; c2 < 8; c2++) {
//
//                    bool validMove = false;
//
//                    if (abs(piece) == WPAWN)
//                        validMove = ValidPawnMove(board, r1, c1, r2, c2);
//                    else if (abs(piece) == WROOK)
//                        validMove = ValidRookMove(board, r1, c1, r2, c2);
//                    else if (abs(piece) == WKNIGHT)
//                        validMove = validKnightMove(board, r1, c1, r2, c2);
//                    else if (abs(piece) == WBISHOP)
//                        validMove = validBishopMove(board, r1, c1, r2, c2);
//                    else if (abs(piece) == WQUEEN)
//                        validMove = ValidQueenMove(board, r1, c1, r2, c2);
//                    else if (abs(piece) == WKING)
//                        validMove = validKingMove(board, r1, c1, r2, c2);
//
//                    if (!validMove)
//                        continue;
//
//                    // Simulate move
//                    int temp = board[r2][c2];
//                    board[r2][c2] = piece;
//                    board[r1][c1] = EMPTY;
//
//                    bool stillInCheck = isKingInCheck(board, whiteTurn);
//
//                    // Undo move
//                    board[r1][c1] = piece;
//                    board[r2][c2] = temp;
//
//                    // If ANY move escapes check → not checkmate
//                    if (!stillInCheck)
//                        return false;
//                }
//            }
//        }
//    }
//
//    // No escape found
//    return true;
//}
//
//
//
//
