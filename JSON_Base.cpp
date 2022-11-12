// Base class JSONBase that provides following capabilities:
// Document parsing using RapidJSON
// Serializing to fileand Deserializing from file

#include "JSON_Base.h"

std::string JSON_Base::Serialize() const
{
	rapidjson::StringBuffer ss;
	rapidjson::Writer<rapidjson::StringBuffer> writer(ss);		
	if (Serialize(&writer))
		return ss.GetString();
	return "";
}

bool JSON_Base::Deserialize(const std::string& s)
{
	rapidjson::Document doc;
	if (!InitDocument(s, doc))
		return false;

	Deserialize(doc);

	return true;
}

bool JSON_Base::DeserializeFromFile(const std::string& filePath)
{
	std::ifstream f(filePath);
	std::stringstream buffer;
	buffer << f.rdbuf();
	f.close();

	return Deserialize(buffer.str());
}

bool JSON_Base::SerializeToFile(const std::string& filePath)
{
	std::ofstream f(filePath);
	std::string s = Serialize();
	f << s;
	f.flush();
	f.close();

	return true;
}

bool JSON_Base::InitDocument(const std::string& s, rapidjson::Document& doc)
{
	if (s.empty())
		return false;

	std::string validJson(s);

	return !doc.Parse(validJson.c_str()).HasParseError() ? true : false;
}