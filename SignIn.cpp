#include<iostream>
using namespace std;
int main()
{
    std::string gmail;

    std::string ending = "*gmail.com";

    std::string password;

    std::string final_gmail;

    std::cout<< "Enter your G-main" << std::endl;

    std::getline(cin , gmail);
    
    if(gmail.length() >= ending.length()){
        if(gmail.substr(gmail.length() - ending.length()) == ending ){
            std::cout << "Email verified" << std:: endl;

             gmail = final_gmail;
        }
        else {
            std:: cout <<"Invalid gmail;" << endl;

        }
    }
    std::cout << "enter your password " <<std::endl;
    std::getline(cin , password);

    std :: cout << "Your email address is " << final_gmail << std::endl;
    std::cout << "Your password is " << password << std::endl;
    
   
    


    return 0;
}