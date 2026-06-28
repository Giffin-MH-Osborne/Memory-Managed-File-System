#include "FileSystem.h"
#include <iostream>

int main() {
    FileSystem fs;
    
    std::string choice;
    std::string path;
    std::string data;
    bool running = true;

    while(running){
        std::cin >> choice;
        std::cin.ignore();
        if(choice == "mkdir"){
            std::cout << "Supply values for the following parameters\nPath[0]:";
            std::cin >> path;
            std::cout << "\n";
            fs.mkdir(path);
        }
        else if(choice == "touch"){
            std::cout << "Supply values for the following parameters\nPath[0]:";
            std::cin >> path;
            std::cout << "\n";
            fs.touch(path);
        }
        else if(choice == "ls"){
            fs.ls();
        }
        else if(choice == "cd"){
            std::cout << "Supply values for the following parameters\nPath[0]:";
            std::cin >> path;
            std::cout << "\n";
            fs.cd(path);
        }
        else if(choice == "pwd"){
            fs.pwd();
        }
        else if(choice == "rm"){
            std::cout << "Supply values for the following parameters\nPath[0]:";
            std::cin >> path;
            std::cout << "\n";
            fs.rm(path);
        }
        else if(choice == "cat"){
            std::cout << "Supply values for the following parameters\nPath[0]:";
            std::cin >> path;
            std::cout << "\n";
            fs.cat(path);
        }
        else if(choice == "write"){
            std::cout << "Supply values for the following parameters\nPath[0]:";
            std::cin >> path;
            std::cout << "\nEnter the data to write to file: ";
            std::cin >> data;
            std::cout << "\n";
            fs.write(path, data);
        }
        else if(choice == "tree"){
            fs.tree();
        }
        else if(choice == "exit"){
            running = false;
        }
        else {
            std::cout << "Invalid Command\n";
        }
    }
    return 0;
}