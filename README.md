# TodoList
Pretty self explanatory

There are two versions. One simple command line version created in a one-hour-programathon, and a more sophisticated NCurses version that better suits my personal needs.<br />
<br />
Actual list is saved in "~/.todo". This can be changed in config.h<br />
<br />
To toggle between the two versions, define USE_CURSES in config.h accordingly (1s and 0s)<br />

# Usage
General:<br />
$ todo [task]         # adds task to todo list<br />
$ todo                # launches Curses UI if enabled, otherwise prints todo list and quits<br />
$ todo [options] ...  # executes argument<br />
examples:<br />
$ todo finish readme.md for github # addends "finish readme.md for github" to ~/.todo<br />
$ todo --remove 5 # removes item "5" from todo list (note increment starts at 0 cuz l33t)<br />

# Options
--help                  duh<br />
--remove itemnum        removes item via number itemnum (starts at 0)<br />
--list                  prints list and quits<br />

# Types
typedef std::Vector<std::string> vecstr;  For simplicities sake<br />
file_opener(const char* filepath);  Opens file for read/write to/from vecstr and append from string.<br />
config_t; configuration type. default config is variable "config"<br />
