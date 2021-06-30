#include "pch.h"
#include "framework.h"

#include "client.h"
#include "endpoints.h"
#include "objects.h"

json Client::RawGetLanguageByName(std::string name) {
	auto response = cpr::Get(
		cpr::Url{
			DataLanguageByName
		},
		cpr::Parameters{
			{
				"name", name
			}
		},
		cpr::Header{
			{
				"Authorization", this->auth_token
			}
		}
	);

	return json::parse(response.text);
}

Language Client::GetLanguageByName(std::string name) {
	auto rawLanguage = this->RawGetLanguageByName(name);

	Language language;
	language.from_json(rawLanguage, language);

	return language;
}

json Client::RawGetLanguageByExtension(std::string extension) {
	auto response = cpr::Get(
		cpr::Url{
			DataLanguageByExt
		},
		cpr::Parameters{
			{
				"extension", extension
			}
		},
		cpr::Header{
			{
				"Authorization", this->auth_token
			}
		}
	);
	return json::parse(response.text);
}

Language Client::GetLanguageByExtension(std::string extension) {
	auto rawLanguage = this->RawGetLanguageByExtension(extension);

	Language language;
	language.from_json(rawLanguage, language);

	return language;
}