#include <iostream>
#include <fstream>;
#include <string>;
#include <vector>;
#include <sstream>;

//This is memory variable will store all the variables declared
std::vector <int> memory;
std::vector <int> methods;
std::vector <std::string> IDs;
std::vector <std::string> Method_IDs;
std::fstream file;
std::string path;
std::string keywords = "comrade if -> + - = / * true false manifesto propaganda ; 1 2 3 4 5 6 7 8 9 0 worker alert += -+ /= *= contribute gulag sendToGulag censor contribute revolutionize";
std::vector <int> sum;

void compile();
void createIntVariable(std::string name, int data);
int  getIntVariable(std::string name);
int  methodMath(int operationID, int previousValue, int nextValue);
void intMath (int operationID , std::string name, int addValue);
void setIntVariable(std::string name, int data);
void setMethod(std::string, int data);
bool isKeyword (std::string name);
bool isNumber  (std::string data);
bool comparison(std::string condition , int previousValue, int nextValue);

unsigned int gulagPosition;

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

        std::string code;
        std::vector <std::string> lines;
        std::string sa;

        while (getline(file, sa)) {

            lines.push_back(sa);

        }

        system("cls");

        std::cout << "Running a revolution called: " << path << std::endl;
        std::cout << "-----------------------------" << std::endl;

        //This k variable will itarate the while loop down below.
        //The reason of using a while instead of a loop is because the k number cold be modified in case a loop is called
        unsigned int k = 0;

        //This variable is a flag for when a loop is detected.
        //So for example let's say the word sendToGulag is detected, then loop will be equal to true.
        //This will comunicate the for loop inside with the main one (the one below) and let the loop while ( k < lines.size()) know that he is going to go back.
        bool loop = false;

        while ( k < lines.size()) {
        
            std::string sentence = lines[k];
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

                
                //Comment
                //the character ; will be used to denotate a comment
                if (words[i] == ";" || words[i][0] == ';') {
                    break;
                }

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

                if (words[i] == "if") {

                    int previousValue = 0, nextValue = 0;

                    if (isNumber(words[i + 1])) {

                        previousValue = std::stoi(words[i + 1]);

                    }
                    else {

                        previousValue = getIntVariable(words[i + 1]);

                    }

                    if (isNumber(words[i + 3])) {

                        nextValue = std::stoi(words[i + 3]);

                    }
                    else {

                        nextValue = getIntVariable(words[i + 3]);

                    }

                    if (!comparison(words[i + 2], previousValue, nextValue)) {

                        break;

                    }
                }

                if (words[i] == "gulag") {

                    gulagPosition = k;
                    break;

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

                if (words[i] == "+=") {

                    if (isNumber(words[i + 1])) {

                        intMath(0, words[i - 1], std::stoi(words[i + 1]));

                    }
                    else {

                        intMath(0, words[i - 1], getIntVariable(words[i + 1]));

                    }

                }

                if (words[i] == "-=") {

                    if (isNumber(words[i + 1])) {

                        intMath(1, words[i - 1], std::stoi(words[i + 1]));

                    }
                    else {

                        intMath(1, words[i - 1], getIntVariable(words[i + 1]));

                    }

                }

                if (words[i] == "*=") {

                    if (isNumber(words[i + 1])) {

                        intMath(2, words[i - 1], std::stoi(words[i + 1]));

                    }
                    else {

                        intMath(2, words[i - 1], getIntVariable(words[i + 1]));

                    }

                }

                if (words[i] == "/=") {

                    if (isNumber(words[i + 1])) {

                        intMath(3, words[i - 1], std::stoi(words[i + 1]));

                    }
                    else {

                        intMath(3, words[i - 1], getIntVariable(words[i + 1]));

                    }

                }

                //Logical operators


                //functions

                if (words[i] == "alert" || words[i] == "propaganda") {

                    std::string msg;

                    for (unsigned short int j = i + 2; j < words.size(); j++) {

                        if (words[j] != ")") {

                            try {

                                msg += (words[j] + " ");

                            }
                            catch (std::exception& e) {

                                std::cout << errors(2000, "");

                            }

                        }
                        else { break; }

                    }

                    std::cout << msg;
                }

                if (words[i] == "manifesto") {

                    std::cout << getIntVariable(words[i + 2]);

                }

                if (words[i] == "progress") {

                    std::cout << "\n";

                }

                if (words[i] == "censor" || words[i] == "revolutionize") {
                
                    system("cls");
                
                }

                //Use contribute as a name for a function for user input 

                if (words[i] == "contribute") {

                    int t = 0;
                    std::cin >> t;

                    if (words[i + 2] != ")" && words[i + 2] != "(" && words[i + 2] != "()") {

                        setIntVariable(words[i + 2], t);

                    }
                }    

                //This condition must always be cheked at the end
                if (words[i] == "sendToGulag") {

                    loop = true;
                    break;
       
                }

            }

            code += sa;

            if (!loop) {
                k++;
            }
            else {

                k = gulagPosition;
                loop = false;
            }
            
   
        }

        
  
    file.close();

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

bool comparison(std::string condition, int previousValue, int nextValue) {

    if (condition == "==") {
    
        if (previousValue == nextValue){
        
            return true;

        }
        else {

            return false;

        }   
    }
    else if (condition == "!=") {

        if (previousValue != nextValue) {

            return true;

        }
        else {

            return false;

        }
    }
    else if (condition == "<") {

        if (previousValue < nextValue) {

            return true;

        }
        else {

            return false;

        }
    }
    else if (condition == ">") {

        if (previousValue > nextValue) {

            return true;

        }
        else {

            return false;

        }
    }
    else if (condition == "<=") {

        if (previousValue <= nextValue) {

            return true;

        }
        else {

            return false;

        }
    }
    else if (condition == ">=") {

        if (previousValue >= nextValue) {

            return true;

        }
        else {

            return false;

        }
    }

}

//All this methods are for manipulating int variables

void createIntVariable(std::string name , int data) {

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

//The methods down below are for creation and manipulation of methods or functions

void setMethod(std::string name, int data) {

    for (unsigned int i = 0; i < Method_IDs.size(); i++) {

        if (Method_IDs[i] == name) {

            try {

                methods[i] = data;

            }
            catch (std::exception& e) {

                std::cout << "comrade " + name + " can't be equal to " << data << e.what() << std::endl;

            }
        }
    }

}

int methodMath(int operationID, int previousValue, int nextValue) {

    switch (operationID) {
    
        case 0: return previousValue + nextValue; break;
        case 1: return previousValue - nextValue; break;
        case 2: return previousValue * nextValue; break;
        case 3: return previousValue / nextValue; break;
    
    }
}


//This method returns a string with an error message depending of the given ID , the string variableName is for errors that need to be more specific but if is not you can you pass "" in that field

std::string errors(int ID , std::string variableName) {

    switch (ID) {
        
        case 1000: return "Error 1000: Ilegal name '" + variableName + "'" + " for comrade"; break;
        case 1001: return "Error 1000: Ilegal name '" + variableName + "'" + " for worker"; break;
        case 1917: return "Error 1917: File Liberation Unsuccessful!, The requested file is missing in action."; break;
        case 2000: return "Error 2000: socialist print syntax error."; break;
    
    }

    std::cout << "The CCCP does not have a place for errors";
}

