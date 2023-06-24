#include "user.h"
#include <fstream>
#include <string>
void user::addToFile(){
    ofstream file("users.txt",ios::binary);
    if(file.is_open()){
        file.write(account.data(),account.size() + 1);
        file.write(password.data(),password.size() + 1);
        file.close();
    }
}
void user::searchInFile(){
    string tempAccount,tempPassword;
    ifstream file("user.txt",ios::binary);
    if(file.is_open()){
        while(1){
            std::getline(file, tempAccount, '\0');
            std::getline(file, tempPassword, '\0');
        }

        file.close();
    }
}
