#include<iostream>

int main()
{
    const int KING = 1, QUEEN = 1, ROOK = 2, BISHOP = 2, KNIGHT = 2, PAWN = 8;
    int k, q, r, b, kn, p;

    std::cin >>  k >> q >> r >> b >> kn >> p;

    std::cout << KING - k << " " << QUEEN - q << " " << ROOK - r << " " << BISHOP - b << " " << KNIGHT - kn << " " << PAWN - p;



}