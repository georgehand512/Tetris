// Base class JSONBase that provides following capabilities:
// Document parsing using RapidJSON
// Serializing to fileand Deserializing from file

#pragma once
#include "include\rapidjson\rapidjson.h"	// Rapidjson JSON required include
#include "include\rapidjson\document.h"		// Rapidjson JSON required include
#include "include\rapidjson\prettywriter.h"	// Rapidjson JSON required include
#include <string>							// String standard library
#include <sstream>							// String streams standard library
#include <fstream>							// Standard file steam library

class JSON_Base
{
protected:
	bool InitDocument(const std::string& s, rapidjson::Document& doc);


public:
	bool DeserializeFromFile(const std::string& filePath);
	bool SerializeToFile(const std::string& filePath);

	virtual std::string Serialize() const;
	virtual bool Deserialize(const std::string& s);
	virtual bool Deserialize(const rapidjson::Value& obj) = 0;
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const = 0;

};

