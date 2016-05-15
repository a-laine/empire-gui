#include "tile.hpp"


Tile::Tile(Tile::Type type) :
	m_type(type),
	m_piece(0),
	m_visible(true)
{
}

Tile::Type Tile::getType()
{
	return m_type;
}

void Tile::setVisible(bool visible)
{
	m_visible = visible;
}

bool Tile::isVisible()
{
	return m_visible;
}

void Tile::putPiece(Piece* piece)
{
	m_piece = piece;
}

Piece*Tile::getPiece()
{
	return m_piece;
}
