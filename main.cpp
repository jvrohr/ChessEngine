#include <iostream>
#include <vector>

enum class MoveType {
    NORMAL, ENPASSANT, CASTLING, PROMOTION
};

class Position {
public:
    int row, column;

    Position(int row = -1, int column = -1) : row(row), column(column) {}

    bool isValid() const {
        return row >= 0 && row < 8 && column >= 0 && column < 8;
    }

    bool operator==(const Position& other) const {
        return row == other.row && column == other.column;
    }

    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
};

class ChessPiece {
public:
    char type;
    Position currentPos;

    ChessPiece(char t = ' ', Position position = Position()) : type(t), currentPos(position) {}

    char getType() const { return type; }
    bool isWhitePiece() const { return std::isalpha(type) && !std::islower(type); }
    void display() const { std::cout << (type == ' ' ? '.' : type); }
};

class Move {
public:
    Position initialPos;
    Position finalPos;
    MoveType type;

    Move(Position initialPos, Position finalPos, MoveType type = MoveType::NORMAL) 
        : initialPos(initialPos), finalPos(finalPos), type(type) {}

    bool isValid() const {
        return finalPos.isValid();
    }
};

class Board {
public:
    ChessPiece board[8][8];

    Board() { InitializeBoard(); }

    void InitializeBoard() {
        // Inicializa todas as casas com peças vazias
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = ChessPiece(' ', Position(i, j));
            }
        }

        // Peões
        for (int i = 0; i < 8; i++) {
            board[1][i] = ChessPiece('p', Position(1, i));
            board[6][i] = ChessPiece('P', Position(6, i));
        }

        // Torres
        board[0][0] = board[0][7] = ChessPiece('r', Position(0, 0));
        board[7][0] = board[7][7] = ChessPiece('R', Position(7, 0));

        // Cavalos
        board[0][1] = board[0][6] = ChessPiece('n', Position(0, 1));
        board[7][1] = board[7][6] = ChessPiece('N', Position(7, 1));

        // Bispos
        board[0][2] = board[0][5] = ChessPiece('b', Position(0, 2));
        board[7][2] = board[7][5] = ChessPiece('B', Position(7, 2));

        // Rainhas
        board[0][3] = ChessPiece('q', Position(0, 3));
        board[7][3] = ChessPiece('Q', Position(7, 3));

        // Reis
        board[0][4] = ChessPiece('k', Position(0, 4));
        board[7][4] = ChessPiece('K', Position(7, 4));
    }

    void display() const {
        for (int i = 0; i < 8; i++) {
            std::cout << 8 - i << " | ";  // Exibir números das fileiras
            for (int j = 0; j < 8; j++) {
                std::cout << " ";
                board[i][j].display();
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "  -------------------------" << std::endl;
        std::cout << "     A  B  C  D  E  F  G  H" << std::endl;
    }

    bool movePiece(Position from, Position to) {
        if (!from.isValid() || !to.isValid()) return false;

        board[to.row][to.column] = board[from.row][from.column];
        board[to.row][to.column].currentPos = to;

        board[from.row][from.column] = ChessPiece(' ', from);  // Remove a peça da posição original
        return true;
    }
};

int main() {
    Board board;
    board.display();

    // Exemplo de movimento
    std::cout << "\nMovendo peão de E2 para E4...\n";
    board.movePiece(Position(6, 4), Position(4, 4));
    board.display();

    return 0;
}
