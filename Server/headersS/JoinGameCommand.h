/*
 * JoinGameCommand.h
 */

#ifndef JOINGAMECOMMAND_H_
#define JOINGAMECOMMAND_H_

#include "Command.h"
#include "GameManager.h"

class JoinGameCommand: public Command {
public:
	JoinGameCommand(GameManager *info);
	virtual ~JoinGameCommand();
	void setArgs(vector<string> args, int socket);
	void execute(Server *server);

private:
	GameManager *info;
	string name;
	int player2Socket;
};

#endif /* JOINGAMECOMMAND_H_ */
