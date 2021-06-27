#pragma once

#include <string>
#include "TextRenderer.h"
#include "utils/user.h"
#include <map>
#include "model/Client.h"

class StartPage
{
    public:
        StartPage(SDL_Renderer *, Client* client);
        void show();
        bool handle(SDL_Event event);
        user_t getCurrentUser() const {return currentUser;};
        ~StartPage();

    private:
        SDL_Renderer *renderer;
        TextRenderer *textRenderer;
        std::string username = "";
        std::string password = "";
        std::string resultMsg = "";
        user_t currentUser;
        Client *client;
        
        char focus = 0;

        int setFocusColor(int);
        bool mouseOnUsernameButton(int, int);
        bool mouseOnPasswordButton(int, int);
        bool mouseOnDoneButton(int, int);
        void showError();
        bool login(std::string username, std::string password);
};