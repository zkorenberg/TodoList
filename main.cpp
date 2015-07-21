/* 
 * File:   main.cpp
 * Author: Zachary Korenberg
 *
 * Created on July 20, 2015, 11:14 PM
 */


#include <cstdlib>
#include <cstring>
#include <iostream>

#include "config.h" // at top for macros
#include "file_opener.h"



using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    // check if passed argumenmt
    //config_t config; // define config
    file_opener file(config.ListLocation.c_str());
    //file_opener file("~/.todo");
    if(argc > 1){ // 1 (argv[0]) is file location
        if( strcmp( argv[1], "--help") == 0 ){
            cout << "Usage: todo <task to complete>" << endl <<
                    "A UI will launch if no arguments are passed.";
            return 0;
        }else if( strcmp( argv[1], "--remove") == 0 ){
            int i = stoi(argv[2]);
            vecstr list = file.read();
            list.erase(list.begin()+i);
            file.write(list);
            return 0;
        }else if( strcmp( argv[1], "--list") == 0 ){
            vecstr list = file.read();
            for(int i=0; i<list.size(); i++){
                cout << i << ":\t" << list[i] << endl;
            }
            return 0;
        }else{
            string task; // empty
            for(int i=1; i<argc; i++){ // 1 argument is file
                if(i!=1) task += " ";
                task += argv[i];
            }
            if(file.append(task)){
                return 0;
            }else{
                return 1;
            }
        }
        return 0;
    }
    // command line mode
    if(!USE_CURSES){
        vecstr list = file.read();
        for(int i=0; i<list.size(); i++){
            cout << i << ":\t" << list[i] << endl;
        }
        return 0;
    }
    
}

