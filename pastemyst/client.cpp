#include "pch.h"
#include "framework.h"

#include "client.h"
#include "endpoints.h"

Client::Client() {
	// ...
}

Client::Client(std::string auth_token) {
	this->auth_token = auth_token;
}

void Client::Authorize(std::string auth_token) {
	this->auth_token = auth_token;
}

bool Client::IsAuthorized() {
	return this->auth_token != "";
}

// TODO: To avoid duplication
void Client::Get() {

}
void Client::Post() {

}
void Client::Patch() {

}
void Client::Delete () {

}
