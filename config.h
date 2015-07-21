/* 
 * File:   config.h
 * Author: kushmaster
 *
 * Created on July 20, 2015, 11:19 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

typedef std::vector<std::string> vecstr; // dank

#define DEBUG       1
#define USE_CURSES  0
#define USE_COLOR   0 // will program l8r

class config_t {
public:
    std::string ListLocation;
    std::string ANSIColorCode;
    config_t load(){
        std::string homedir;
        if( (homedir = getenv("HOME")).length() == 0){ // emtpy
            homedir = getpwuid(getuid())->pw_dir;
        }
        ListLocation = homedir + "/.todo";
        
        
        return *this;
    }
    bool save(){
        // empty until i make config
        return true;
    }
    config_t(){ load();} // 37 is white
    ~config_t(){ save(); }
    void setANSIColorCode(int i){
        ANSIColorCode = "\033[0;" + std::to_string(i) + "m";
    }
}config;


#endif	/* CONFIG_H */

