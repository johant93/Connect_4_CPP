#include "Board.h"

/**
 * \brief Constructor of the object Board.
 * \param dimension
 * complexity : O(n^2) (such that n = dimension).
 */
Board::Board(const size_t dimension) {
    matrix = new char*[dimension];
    for(size_t i = 0; i < dimension; i++)
        matrix[i] = new char[dimension];
    this->dimension = dimension;
    for (size_t j = 0; j < dimension; j++) {
        for (size_t k = 0; k < dimension; k++) {
            matrix[j][k] = '.';
        }
    }
}

char& Board::operator[] (vector<int> point) {
    if (point[0] < 0 || point[0] >= dimension || point[1] < 0 || point[1] >= dimension )
        throw IllegalCoordinateException(point[0], point[1]);
    return matrix[point[0]][point[1]];
}

//privates methods.

//friends operators.

/**
 * \brief This friend operator print the board. (As toString in Java).
 * \param os
 * \param board
 * \return os.
 * Complexity : O(1).
 */
ostream& operator<< (ostream& os, const Board& board) {
    for (size_t i = 0; i < board.dimension; i++) {
        for (size_t j = 0; j < board.dimension; j++) {
            os << board.matrix[i][j];
        }
        os << endl;
    }
    return os;
}