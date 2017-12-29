/*
 * JoinGameCommand.cpp
 */

#include "headersS/JoinGameCommand.h"
#include "headersS/Server.h"

JoinGameCommand::JoinGameCommand(GameManager* info): info(info), name(0), player2Socket(0) {
}

JoinGameCommand::~JoinGameCommand() {
}

void JoinGameCommand::setArgs(vector<string> args, int socket) {
	name.assign(args.front());
	player2Socket = socket;
}

void JoinGameCommand::execute(Server* server) {
	bool success = info->startGame(name, player2Socket);
	if(success) {
		server->passInt(player2Socket, 2);
	} else {
		server->passInt(player2Socket, -2);
	}
}
