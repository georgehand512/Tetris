//#include <string>
#include "JSON_Player.h"

using namespace std;


JSON_Player::JSON_Player()
{}

JSON_Player::JSON_Player(int rank, string name, int score, int level, int rows, int remain, int high)
{
	Ranking = rank;
	Name = name;
	Score = score;
	Level = level;
	RowsCleared = rows;
	RowsToNextLevel = remain;
	HighScoretoBeat = high;
}

JSON_Player::~JSON_Player()
{}


bool JSON_Player::Deserialize(const rapidjson::Value& obj)
{

	set_Ranking(obj["ranking"].GetInt());
	set_Name(obj["name"].GetString());
	set_Score(obj["score"].GetInt());
	set_Level(obj["level"].GetInt());
	set_RowsCleared(obj["rows"].GetInt());

	return true;
}



bool JSON_Player::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	writer->StartObject();

	writer->String("ranking");
	writer->Int(Ranking);

	writer->String("name");
	writer->String(Name.c_str());

	writer->String("score");
	writer->Int(Score);

	writer->String("level");
	writer->Int(Level);

	writer->String("rows");
	writer->Int(RowsCleared);

	writer->EndObject();

	return true;
}

void JSON_Player::Player_to_JSON_Player(Player player_convert)
{
	Name = player_convert.getName();
	Score = player_convert.getScore();
	Level = player_convert.getLevel();
	RowsCleared = player_convert.getRows();
	RowsToNextLevel = player_convert.getRemaining();
	HighScoretoBeat = player_convert.getHighScore();
}

void JSON_Player::update_Ranking(int rank)
{
	Ranking = rank;
}

