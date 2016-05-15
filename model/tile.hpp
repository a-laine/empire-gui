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
		void setGraphicsObject(void* object);
		void* getGraphicsObject();


	private:
		Type m_type;
		Piece* m_piece;
		bool m_visible;
		void* m_graphics;
};

#endif // TILE_HPP
