#include <iostream>
#include <fstream>;
#include <string>;
#include <vector>;
#include <sstream>;

//This is memory variable will store all the variables declared
std::vector <int> memory;
std::vector <std::string> IDs;
std::fstream file;
std::string path;
std::string keywords = "comrade if -> + - = / * true false manifesto propaganda ; 1 2 3 4 5 6 7 8 9 0 send worker";
std::vector <int> sum;

void compile();
void run();
void createIntVariable(std::string name, int data);
int getIntVariable(std::string name);
void intMath (int operationID , std::string name, int addValue);
void setIntVariable(std::string name, int data);
bool isKeyword(std::string name);
bool isNumber (std::string data);

std::string errors(int ID , std::string variableName);

int main()
{   
    std::cin >> path;
    file.open(path , std::ios::in);

    try {
        if (file.is_open()) {
            compile();
        }
        else {
            throw std::runtime_error(errors(1917 , ""));
        }
    }
    catch (const std::exception& e) {
        std::cout << "" << e.what() << std::endl;
    }
}


void compile() {

    std::cout << "Starting a revolution..." << std::endl; 

        std::string code;

        std::string sa;
        while (getline(file, sa)) {

            std::string sentence = sa;
            std::istringstream iss(sentence);
            std::string word;
            std::vector <std::string> words;

            unsigned int position = 0;

            //Keywords
            while (iss >> word) {

                words.push_back(word);
                position++;
            }

            for (unsigned short int i = 0; i < words.size(); i++) {
                
                //Operators

                if (words[i] == "comrade") {
                
                    try {

                        if (!isKeyword(words[i + 1])) {
                        
                            try {

                                createIntVariable(words[i + 1], 0);

                            }
                            catch (std::exception& e) {

                                std::cout << "An error ocurred" << e.what();

                            }
                                   
                        }
                        else {
                        
                            std::cout << errors(1000, words[i + 1]);
                            break;
                            
                        }

                    }
                    catch (std::exception& e) {

                        std::cout << "An error ocurred" << e.what();

                    }
                
                }
                
                //math operators
                if (words[i] == "=") {
               
                    if (isNumber(words[i + 1])) {

                        setIntVariable(words[i - 1], std::stoi(words[i + 1]));
                    }
                    else {
                    
                        setIntVariable(words[i - 1], getIntVariable(words[i + 1]));
                    
                    }
                }

                if (words[i] == "+="){
            
                    if (isNumber(words[i + 1])) {

                        intMath(0 , words[i - 1] , std::stoi(words[i + 1]));

                    }else {
                    
                        intMath(0, words[i - 1], getIntVariable(words[i+1]));
                    
                    }
            
                }

                //Logical operators


                //functions

                if (words[i] == "alert") {
                
                    std::string msg;

                    for (unsigned short int j = i + 2; j < words.size(); j++) {

                        if (words[j] != ")") {
                        
                            try {

                                msg += (" " + words[j]);
                            
                            }
                            catch (std::exception& e ){
                            
                                std::cout << errors(2000, "");

                            }

                        }

                    }

                    std::cout << msg;  
                }
                
                if (words[i] == "manifesto") {
                
                    std::cout << getIntVariable(words[i + 2]);
                
                }
                
                if (words[i] == "progress") {
                
                    std::cout << "\n";
                
                }

                //Use contribute as a name for a function for user input 

                //methods         
            }

            code += sa;
        }

        
  
    file.close();

    run();

}


void run() {



}

//detects if the given string is a keyword
bool isKeyword(std::string name) {

    std::string sentence = keywords;
    std::istringstream iss(sentence);
    std::string word;

    while (iss >> word) {

        if (name == word) {
        
            return true;
        
        }
        else {
        
            return false;
        
        }
    }
}

//Detects if the given string is a number
bool isNumber(std::string data) {

    char numbers[10] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };
    
    bool flag = false;

    for (unsigned short int i = 0; i < 10; i++) {
    
        if (numbers[i] == data[0]) {

            flag = true;
            break;
        
        }
    }

    if (flag) {
    
        return true;
    }
    else { 
        
        return false; 
    }


}

//All this methods are for manipulating int variables

void createIntVariable(std::string name , int data) {

    std::string sentence = keywords;
    std::istringstream iss(sentence);
    std::string word;

        try {

            memory.push_back(data);
            IDs.push_back(name);
        }
        catch (std::exception& e) {
            std::cout << "An error ocurred at variable '" + name + "'" << e.what();
        }  

}

void setIntVariable(std::string name, int data) {

    for (unsigned int i = 0; i < IDs.size(); i++) {

        if (IDs[i] == name) {

            try {
            
                memory[i] = data;
            
            }
            catch (std::exception& e){
            
                std::cout << "comrade " + name + " can't be equal to " << data << e.what() << std::endl;
            
            }
        }
    }
}


int getIntVariable(std::string name) {

    for (unsigned int i = 0; i < IDs.size(); i++) {
    
        if (IDs[i] == name) {
     
            return memory[i];     
        }  
    }

}


void intMath (int operationID, std::string name, int addValue) {

    int t = 0;

    switch (operationID) {

        case 0: t = getIntVariable(name) + addValue; setIntVariable(name, t); break;
        case 1: t = getIntVariable(name) - addValue; setIntVariable(name, t); break;
        case 2: t = getIntVariable(name) * addValue; setIntVariable(name, t); break;
        case 3: t = getIntVariable(name) / addValue; setIntVariable(name, t); break;

    }

}

//This method returns a string with an error message depending of the given ID , the string variableName is for errors that need to be more specific but if is not you can you pass "" in that field

std::string errors(int ID , std::string variableName) {

    switch (ID) {
        
        case 1000: return "Error 1000: Ilegal name '" + variableName + "'" + " for comrade"; break;
        case 1917: return "Error 1917: File Liberation Unsuccessful!, The requested file is missing in action."; break;
        case 2000: return "Error 2000: socialist print syntax error."; break;
    
    }

    std::cout << "The CCCP does not have a place for errors";


}

