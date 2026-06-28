#pragma once
#include <string>
#include <vector>
#include "Directory.h"
#include "File.h"

class FileSystem {
    Directory* root;
    Directory* current;
public:
    FileSystem(){
        root = new Directory("/", nullptr);
        current = root;
    }

    ~FileSystem(){
        delete root; //recursively deletes entire tree
    }

    void mkdir(const std::string& path);
    void touch(const std::string& path);
    void ls();
    void cd (const std::string& path);
    void pwd() const;
    void rm(const std::string& path);
    void cat(const std::string& path);
    void write(const std::string& path,const std::string& data);
    void tree() const;

private:
    Node* resolvePath(const std::string& path);
    std::vector<std::string> tokenize(const std::string& path) const;
};