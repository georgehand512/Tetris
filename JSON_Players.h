#pragma once
#include "JSON_Base.h"
#include "JSON_Player.h"	// Include BASE/Parent class
#include <list>				// String standard library


class JSON_Players : public JSON_Base
{
private:
	std::list<JSON_Player> players;

public:
	virtual ~JSON_Players() {};
	virtual bool Deserialize(const std::string& s);
	virtual bool Deserialize(const rapidjson::Value& obj) { return false; };
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;


	// Getters/Setters.
	std::list<JSON_Player>& PlayersList() { return players; }

};

