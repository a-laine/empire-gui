#ifndef TILE_HPP
#define TILE_HPP

#include "piece.hpp"


class Tile
{
	public:
		enum Type {
			GROUND,
			WATER
		};

		Tile(Type type);

		Type getType();
		void setVisible(bool visible);
		bool isVisible();
		void putPiece(Piece* piece);
		Piece* getPiece();


	private:
		Type m_type;
		Piece* m_piece;
		bool m_visible;
};

#endif // TILE_HPP
