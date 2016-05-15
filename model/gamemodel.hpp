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

		void setMapWidth(int width);
		void setMapHeight(int height);
		int getMapWidth();
		int getMapHeight();
		void setPlayerId(int id);
		int getPlayerId();
		void setTile(QPoint position, Tile* tile);
		void addPiece(int id, Piece* piece);
		Tile* getTile(QPoint position);
		Piece* getPiece(int id);
		void removeTile(QPoint position);
		void removePiece(int id);

	private:
		QPoint mapSize;
		int playerId;

		QHash<QPair<int,int>,Tile*> tiles;
		QHash<int,Piece*> units;
};

#endif // GAMEMODEL_HPP
