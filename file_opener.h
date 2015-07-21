/* 
 * File:   file_opener.h
 * Author: kushmaster
 *
 * Created on July 20, 2015, 11:27 PM
 */

#ifndef FILE_OPENER_H
#define	FILE_OPENER_H

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sys/stat.h>

#ifdef DEBUG
#include <iostream>
#endif
// opens, closes, and writes const char * vector

class file_opener{
    const char* filepath;
    std::fstream file;
public:
    file_opener(const char* _filepath):filepath(_filepath){
        // make sure file exists
        file.open(filepath, std::ios::out | std::ios::app);
        file << std::flush;
        file.close();
    }

    std::vector<std::string> read(){
        file.open(filepath, std::ios::in); // in
        if(!file.is_open()) throw std::runtime_error("file no open");
        std::vector<std::string> retvect;
        std::string line;
        //while(file >> line)
        while(std::getline(file,line))
            retvect.push_back(line);
        file.close();
        return retvect;
    }
    bool write(std::vector<std::string> vector){
        file.open(filepath, std::ios::out | std::ios::trunc);
        if(!file.is_open()) throw std::runtime_error("file no open");
        for(int i=0; i<vector.size(); i++){
            file << vector[i] << std::endl;
        }
        file.close();
        return true;
    }
    bool append(std::string line){
        file.open(filepath, std::ios::out | std::ios::app);
        if(!file.is_open()) throw std::runtime_error("file no open");
        file << line << std::endl;
        file.close();
        return true;
    }
};

#endif	/* FILE_OPENER_H */

