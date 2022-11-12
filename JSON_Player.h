#pragma once
#include "JSON_Base.h"	// Include BASE/Parent class
#include "Player.h"		// Include BASE/Parent class
#include <list>			// Standard list library
#include <string>		// String standard library


class JSON_Player : public JSON_Base, private Player
{
public:

	JSON_Player();
	JSON_Player(int rank, std::string name, int score, int level, int rows, int remain, int high);

	virtual ~JSON_Player();

	virtual bool Deserialize(const rapidjson::Value& obj);
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;

	// Getters/Setters.

	int get_Ranking() const { return Ranking; }
	void set_Ranking(int ranking) { Ranking = ranking; }

	const std::string& get_Name() const { return Name; }
	void set_Name(const std::string& name) { Name = name; }

	int get_Score() const { return Score; }
	void set_Score(int score) { Score = score; }

	int get_Level() const { return Level; }
	void set_Level(int level) { Level = level; }

	int get_RowsCleared() const { return RowsCleared; }
	void set_RowsCleared(int rows) { RowsCleared = rows; }

	void Player_to_JSON_Player(Player player_convert);

	void update_Ranking(int rank);

};

