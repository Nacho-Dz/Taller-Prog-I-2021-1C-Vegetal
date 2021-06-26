#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <vector>
#include "../utils/estadoNivel.h"
#include "../configuration.hpp"
#include <queue>
#include <map>

class Server {
    public:
        Server(char* port);
        int startServer();
    
    private:
        int maxPlayers;
        int serverSocket;
        std::vector<int> clientSockets;
        void startGame(configuration::GameConfiguration config);
        static int sendView(int clientSocket, estadoNivel_t* view);
        static int receiveCommand(int clientSocket, controls_t* controls);
        static void* handleCommand(void* handleCommandArgs);
        static void* acceptNewConnections(void* server);
        struct sockaddr_in serverAddress;
        struct sockaddr_in clientAddress;
        int clientAddrLen;
        std::queue<int> clientSocketQueue;
        std::map<std::string, user_t> users;
        std::map<std::string, user_t> connected_users;
        std::vector<user_t> connectedUsers;
        static void* z_connectToClient(void* arguments);
        //bool z_userAlreadyConnected(user_t user);
        //int z_checkUser(user_t player, std::vector<user_t> users);
        int z_startLogin(int client);
        int z_receiveLogin (int client, user_t* player);
        int z_sendLoginResponse (int client, int* response);
};