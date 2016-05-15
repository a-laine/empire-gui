#include "piece.hpp"


Piece::Piece(int id, int type, int ownerId) :
	m_id(id),
	m_type(type),
	m_team(ownerId),
	m_graphics(0)
{
}

int Piece::getId()
{
	return m_id;
}

int Piece::getType()
{
	return m_type;
}

int Piece::getOwner()
{
	return m_team;
}

void Piece::setGraphicsObject(void* object)
{
	m_graphics = object;
}

void* Piece::getGraphicsObject()
{
	return m_graphics;
}

void Piece::addTransported(Piece* transported)
{
	m_transported.insert(transported);
}

void Piece::removeTransported(Piece* transported)
{
	m_transported.remove(transported);
}

QSet<Piece*> Piece::getTransported()
{
	return m_transported;
}
