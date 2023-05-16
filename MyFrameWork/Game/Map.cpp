#include "Map.h"
#include <iostream>

// >> chuyển dịch bit
const auto ADD_COL = (SCREEN_WIDTH >> 4) + 1;
const auto MOVE_TILE = (TILE_SIZE >> 1);

Map::Map(int level)
{
	std::ifstream ifile;
	char fileName[30];
	int numSetTiles;
	//sprintf_s(fileName, "Resources\\Texts\\matrix%d.txt", level);

	sprintf_s(fileName, "Resources\\Maps\\map1.txt", level);
	// Lấy thông tin hàng, cột và chiều dài, rộng của Map tương ứng
	ifile.open(fileName);
	ifile >> numSetTiles;
	ifile >> columns;
	ifile >> rows;
	width = columns * 16;
	height = rows * 16;
	//width = columns << 4;
	//height = rows << 4;

	rect.width = width;
	rect.height = height;
	rect.x = 0;
	rect.y = rect.height;

	// Tải các Sprite tương ứng của map vào Factory
	switch (level)
	{
	case 1:
		mapLevel = MAP1;
		break;

	case 2:
		mapLevel = MAP2;
		break;

	case 3:
		mapLevel = MAP3;
		break;
	}

	auto sprites = SpriteFactory::GetInstance();
	//for (int i = 0; i < numSetTiles; ++i)
	//{

	//	sprites->AddSprite(new Sprite(mapLevel, i << 4, 0, i + 1 << 4, 16));
	//}

	for (int row = 0; row < 12; ++row)
	{
		for (int column = 0; column < 11; ++column)
		{
			sprites->AddSprite(new Sprite(mapLevel, column * 16, row *16, column + 1 << 4, row + 1 << 4));
		}

	}

	// Tạo ma trận tương ứng của Map đang xét
	mapTiles = new int* [rows];
	for (int r = 0; r < rows; ++r)
	{
		mapTiles[r] = new int[columns];
		for (int c = 0; c < columns; ++c)
		{
			ifile >> mapTiles[r][c];
		}
	}
	ifile.close();

	
}

void Map::Update()
{
	camera->Update(this->rect);
	cBegin = max(0, camera->x / 16);
	cEnd = min(cBegin + ADD_COL, columns);
}

void Map::Render()
{
	auto sprites = SpriteFactory::GetInstance();

	for (auto r = 0; r != rows; ++r)
	{
		for (auto c = cBegin; c != cEnd; ++c)
		{
			auto sprite = sprites->GetSprite(mapLevel, mapTiles[r][c]);
			//sprite->Render((c << 4) + MOVE_TILE - (int)camera->x, (r << 4) + MOVE_TILE + SCREEN_TRANSLATEY);
			sprite->Render((c * 16) + MOVE_TILE - (int)camera->x, (r * 16) + MOVE_TILE + SCREEN_TRANSLATEY);
		}
	}
}