#include <iostream>
#include <fstream>
using namespace std;

class TicTacToe {
public:
    char b[3][3];
    char w;

    TicTacToe() {
        w = ' ';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                b[i][j] = ' ';
    }

    bool move(int r, int c, char p) {
        if (b[r][c] != ' ') return false;
        b[r][c] = p;
        update();
        return true;
    }

    void update() {
        for (int i = 0; i < 3; i++) {
            if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != ' ')
                w = b[i][0];
            if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != ' ')
                w = b[0][i];
        }
        if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != ' ')
            w = b[0][0];
        if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != ' ')
            w = b[0][2];

        bool full = true;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (b[i][j] == ' ') full = false;

        if (full && w == ' ') w = 'D';
    }

    bool full() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (b[i][j] == ' ') return false;
        return true;
    }
};

class Ultimate {
    TicTacToe* boards;
    char big[3][3];
    char p;
    int next;

public:
    Ultimate() {
        boards = new TicTacToe[9];
        p = 'X';
        next = -1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                big[i][j] = ' ';
    }

    Ultimate(const Ultimate& o) {
        boards = new TicTacToe[9];
        for (int i = 0; i < 9; i++) boards[i] = o.boards[i];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                big[i][j] = o.big[i][j];
        p = o.p;
        next = o.next;
    }

    ~Ultimate() {
        delete[] boards;
    }

    void updateBig() {
        for (int i = 0; i < 9; i++)
            big[i / 3][i % 3] = boards[i].w;
    }

    char winner() {
        for (int i = 0; i < 3; i++) {
            if (big[i][0] == big[i][1] && big[i][1] == big[i][2] && (big[i][0] == 'X' || big[i][0] == 'O'))
                return big[i][0];
            if (big[0][i] == big[1][i] && big[1][i] == big[2][i] && (big[0][i] == 'X' || big[0][i] == 'O'))
                return big[0][i];
        }
        if (big[0][0] == big[1][1] && big[1][1] == big[2][2] && (big[0][0] == 'X' || big[0][0] == 'O'))
            return big[0][0];
        if (big[0][2] == big[1][1] && big[1][1] == big[2][0] && (big[0][2] == 'X' || big[0][2] == 'O'))
            return big[0][2];
        return ' ';
    }

    bool valid(int bd, int r, int c) {
        if (bd < 0 || bd > 8 || r < 0 || r > 2 || c < 0 || c > 2) return false;
        if (boards[bd].w != ' ') return false;
        if (boards[bd].b[r][c] != ' ') return false;
        if (next != -1 && bd != next && boards[next].w == ' ' && !boards[next].full())
            return false;
        return true;
    }

    void playMove(int bd, int r, int c) {
        boards[bd].move(r, c, p);
        updateBig();
        next = r * 3 + c;
        if (boards[next].w != ' ' || boards[next].full())
            next = -1;
        p = (p == 'X') ? 'O' : 'X';
    }

    void save() {
        ofstream f("UltimateGame.txt");
        f << p << " " << next << endl;
        for (int i = 0; i < 9; i++) {
            f << boards[i].w << endl;
            for (int r = 0; r < 3; r++)
                for (int c = 0; c < 3; c++)
                    f << boards[i].b[r][c];
            f << endl;
        }
    }

    bool load() {
        ifstream f("UltimateGame.txt");
        if (!f) return false;
        f >> p >> next;
        for (int i = 0; i < 9; i++) {
            f >> boards[i].w;
            for (int r = 0; r < 3; r++)
                for (int c = 0; c < 3; c++)
                    f >> boards[i].b[r][c];
        }
        updateBig();
        return true;
    }

    friend ostream& operator<<(ostream& os, Ultimate& g) {
        for (int br = 0; br < 3; br++) {
            for (int r = 0; r < 3; r++) {
                for (int bc = 0; bc < 3; bc++) {
                    int id = br * 3 + bc;
                    os << "[";
                    for (int c = 0; c < 3; c++) {
                        os << g.boards[id].b[r][c];
                        if (c < 2) os << " ";
                    }
                    os << "]";
                    if (bc < 2) os << " || ";
                }
                os << endl;
            }
            if (br < 2)
                os << "====================================" << endl;
        }
        return os;
    }

    void run() {
        int ch;
        cout << "1 New Game\n2 Load Game\n";
        cin >> ch;
        if (ch == 2 && !load()) cout << "No save found\n";

        while (true) {
            cout << *this;

            char w = winner();
            if (w == 'X' || w == 'O') {
                cout << "Winner: " << w << endl;
                break;
            }

            if (next == -1)
                cout << "Play any board\n";
            else
                cout << "Play in board: " << next << endl;

            cout << "Player " << p << " enter: board row col (-1 to save): ";

            int bd;
            cin >> bd;
            if (bd == -1) {
                save();
                break;
            }

            int r, c;
            cin >> r >> c;

            if (valid(bd, r, c))
                playMove(bd, r, c);
            else
                cout << "Invalid move\n";
        }
    }
};

int main() {
    Ultimate g;
    g.run();
}