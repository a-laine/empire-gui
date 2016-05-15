#include "gamemodel.hpp"

GameModel::GameModel()
{
}

void GameModel::clear()
{
	for(QHash<QPair<int,int>,Tile*>::iterator it = tiles.begin();
		it != tiles.end(); it++)
	{
		delete *it;
	}
	tiles.clear();

	for(QHash<qint32,Piece*>::iterator it = units.begin();
		it != units.end(); it++)
	{
		delete *it;
	}
	units.clear();
}

void GameModel::setTile(QPoint position, Tile* tile)
{
	tiles.insert(QPair<int,int>(position.x(),position.y()), tile);
}

void GameModel::addPiece(int id, Piece* piece)
{
	units.insert(id, piece);
}

Tile* GameModel::getTile(QPoint position)
{
	return tiles.value(QPair<int,int>(position.x(),position.y()), 0);
}

Piece* GameModel::getPiece(int id)
{
	return units.value(id, 0);
}

void GameModel::removeTile(QPoint position)
{
	tiles.remove(QPair<int,int>(position.x(),position.y()));
}

void GameModel::removePiece(int id)
{
	units.remove(id);
}

