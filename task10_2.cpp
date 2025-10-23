#include <iostream>
#include <cmath> 
using namespace std;

struct Chessboard {
    char column; 
    int row;     
};

void inputCell(Chessboard &c) {
    cout << "Enter chess cell (column, row): ";
    cin >> c.column >> c.row;
    if(c.column < 'a' || c.column > 'h' || c.row < 1 || c.row > 8) {
        cout << "Cell does not exist\n";
        exit(1);
    }
}

bool Queen(const Chessboard &q, const Chessboard &c) {
    return (q.column == c.column || q.row == c.row || abs((q.column - 'a') - (c.column - 'a')) == abs(q.row - c.row));
}

int main() {
    Chessboard start, end; 
    inputCell(start);
    inputCell(end);
    if (Queen(start, end)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
