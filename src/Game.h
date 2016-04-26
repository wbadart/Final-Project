/* Game.hpp
 *
 * Interface file for universal base class (engine); Game.
 *
 * APR 2016
 *
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdlib>

// Panda framework should exist on CPATH or use gcc -I...
// Or just use the makefile (be sure PANDA_CPATH and PANDA_LIB
// environment variables are up to date for this)
#include <pandaFramework.h>

class Game{
    public:

        // Primary constructor; able to use command line arguments
        Game(int argc_in, char *argv_in[]);

        // Overloaded constructor which automatically names window
        Game(int argc_in, char *argv_in[], std::string window_name_in);

        // Wrapper to PandaFramework::openwindow(); includes failure check
        bool open_window(void);

        // Wrappers to WindowFramework::load_model
        NodePath load_model(char *model_name);
        NodePath load_model(std::string model_name);

        // Frequently accessed data members; much more efficient to make
        // public, at least for the time being
        PandaFramework framework;
        WindowFramework *window;

        // Set function for player character
        void setpc(NodePath);

        // Move a model
        void move_forward(const Event *, void *);
	void move_backward(const Event *, void *);
	void move_left(const Event *, void *);
	void move_right(const Event *, void *);
	void esc(const Event *, void *);


    private:

        // Tracks whether Game::open_window() has been called
        bool window_is_open;

        // Stores the name of the window
        std::string window_name;

        // Stores the player character object. Will be converted to
        // our object class down the line
        NodePath pc;
};

#endif