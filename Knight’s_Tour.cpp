#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 6;          // practical limit (plain backtracking is very slow beyond 6x6)

// Eight possible knight moves (row and column offsets)
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int board[MAXN][MAXN];
int N;

// Check if (x,y) is inside the board and unvisited
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Print the board
void printBoard() {
    cout << "\nKnight's Tour Path:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(3) << board[i][j] << " ";
        cout << endl;
    }
}

// Recursive backtracking: moveNumber is the number to assign to the next square
bool solveKnightTour(int x, int y, int moveNumber) {
    // Base case: all N*N squares (numbered 1..N*N) have been visited
    if (moveNumber > N * N)
        return true;

    // Trying all 8 possible moves
    for (int k = 0; k < 8; k++) {
        int nextX = x + dx[k];
        int nextY = y + dy[k];

        if (isSafe(nextX, nextY)) {
            board[nextX][nextY] = moveNumber;          // marking the move

            if (solveKnightTour(nextX, nextY, moveNumber + 1))
                return true;                           // success

            board[nextX][nextY] = -1;                  // backtrack
        }
    }
    return false;                                      // dead end
}

int main() {
    int startX, startY;

    cout << "============ Knight's Tour ============\n";
    cout << "Enter board size N (1.." << MAXN << "): ";
    cin >> N;

    if (N < 1 || N > MAXN) {
        cout << "Board size invalid or too large. Use 1.." << MAXN << endl;
        return 1;
    }

    cout << "Enter starting position (row col) [0-based]: ";
    cin >> startX >> startY;

    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "Invalid starting position.\n";
        return 1;
    }

    // Initialize board with -1 (unvisited)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    // Place the knight at the starting position as move 1
    board[startX][startY] = 1;

    cout << "\nSearching for a Knight's Tour...\n";

    if (solveKnightTour(startX, startY, 2)) {
        printBoard();
        cout << "\nA valid tour was found!\n";
    }
    else {
        cout << "\nNo tour was found by the search from the given starting position "
            << "(all possibilities were explored).\n";
    }


    return 0;
}