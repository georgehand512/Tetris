#include "JSON_Players.h"


bool JSON_Players::Deserialize(const std::string& s)
{
	rapidjson::Document doc;
	if (!InitDocument(s, doc))
		return false;

	if (!doc.IsArray())
		return false;

	for (rapidjson::Value::ConstValueIterator itr = doc.Begin(); itr != doc.End(); ++itr)
	{
		JSON_Player player;
		player.Deserialize(*itr);
		players.push_back(player);
	}


	return true;
}

bool JSON_Players::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	writer->StartArray();

	for (std::list<JSON_Player>::const_iterator it = players.begin(); it != players.end(); it++)
	{
		(*it).Serialize(writer);
	}
	writer->EndArray();

	return true;
}



