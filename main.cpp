#include <iostream>

class ChessPiece {
private:
    /*
    | Color | Pawn | Rook | Knight | Bishop | Queen | King |
    | black |  p   |  r   |   n    |   b    |   q   |  k   |
    | white |  P   |  R   |   N    |   B    |   Q   |  K   |
    */
    char type;

public:
    // Constructor
    ChessPiece(char t = ' ') : type(t) {}

    // Getter methods
    char getType() { return type; }
    bool isWhitePiece() { 
        return std::isalpha(type) && !std::islower(type);
    }

    // Display method
    void display() {
        std::cout << type;
    }

    // Display method
    void displayColor() {
        std::cout << (isWhitePiece() ? "White" : "Black") << std::endl;
    }
};

class Board {
public:
    ChessPiece board[8][8];

    Board(){
        InitializeBoard();
    }

    void InitializeBoard(){
        // Pawns
        for(int i = 0; i < 8; i++){
            board[1][i] = ChessPiece('p');
            board[6][i] = ChessPiece('P');
        }
        // Rooks
        board[0][0] = board[0][7] = ChessPiece('r'); // black
        board[7][0] = board[7][7] = ChessPiece('R'); // white

        // Knights
        board[0][1] = board[0][6] = ChessPiece('n');
        board[7][1] = board[7][6] = ChessPiece('N');

        // Bishops
        board[0][2] = board[0][5] = ChessPiece('b');
        board[7][2] = board[7][5] = ChessPiece('B');

        // Queens
        board[0][3] = ChessPiece('q');
        board[7][3] = ChessPiece('Q');

        // Kings
        board[0][4] = ChessPiece('k');
        board[7][4] = ChessPiece('K');
    }

    void display(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                std::cout << ' ';
                board[i][j].display();
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Board board;
    board.display();

    return 0;
}


// Create a matrix representing the table
// Assign each piece a char
// class Board
// class Move
// MoveGenerator
// class Game
// 