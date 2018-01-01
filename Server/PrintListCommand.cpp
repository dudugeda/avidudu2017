/*
 * PrintListCommand.cpp
 */

#include "headersS/PrintListCommand.h"
#include "headersS/Server.h"

PrintListCommand::PrintListCommand(GameManager *info): clientSocket(0), info(info) {
}

//does nothing
PrintListCommand::~PrintListCommand() {
}

/*
 * method to set up socket to send the game list to
 */
void PrintListCommand::setArgs(vector<string> args, int clientSocket) {
	this -> clientSocket = clientSocket;
}

void PrintListCommand::execute() {
	vector<Games>* deadGames = info -> getWaitingGames();
	//send client the size of the games list
	passInt(clientSocket, deadGames->size());
	if(deadGames->empty()) {
		return;
	}
	vector<Games>::iterator it;
	for(it = deadGames->begin(); it != deadGames->end(); it++) {
		int nameSize = it -> name.size();
		const char* name = (it -> name).c_str();
		passString(clientSocket, nameSize, name);
	}
	delete deadGames;
	clientSocket = 0;
}
