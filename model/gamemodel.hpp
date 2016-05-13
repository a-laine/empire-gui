#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "tile.hpp"
#include "piece.hpp"
#include <QHash>
#include <QPair>
#include <QPoint>


class GameModel
{
    public:
        GameModel();

		void clear();

		void setTile(QPoint position, Tile* tile);
		void addPiece(qint32 id, Piece* piece);
		Tile* getTile(QPoint position);
		Piece* getPiece(qint32 id);
		void removeTile(QPoint position);
		void removePiece(qint32 id);

	private:
		QPoint mapSize;
		qint32 playerId;

		QHash<QPair<int,int>,Tile*> tiles;
		QHash<qint32,Piece*> units;
};

#endif // GAMEMODEL_HPP
