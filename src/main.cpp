//code for checking syntax(specially semicolon) checking

// #include <iostream>
// #include <fstream>
// #include <string>

// void checkSyntax(const std::string &filename)
// {
//     std::ifstream file(filename);
//     if (!file.is_open())
//     {
//         std::cerr << "Error opening file: " << filename << std::endl;
//         return;
//     }

//     std::string line;
//     int lineNumber = 0;
//     while (std::getline(file, line))
//     {
//         lineNumber++;
//         // Simple check for missing semicolon
//         if (line.find("int ") != std::string::npos && line.back() != ';')
//         {
//             std::cerr << "Syntax error on line " << lineNumber << ": missing semicolon" << std::endl;
//         }
//     }

//     file.close();
// }

// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
//         return 1;
//     }

//     checkSyntax(argv[1]);

//     return 0;
// }








// code for checking syntax and symatic checking



#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

void checkSyntax(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;
    std::unordered_set<std::string> declaredVariables;

    while (std::getline(file, line))
    {
        lineNumber++;
        // Simple check for missing semicolon
        if (line.find("int ") != std::string::npos && line.back() != ';')
        {
            std::cerr << "Syntax error on line " << lineNumber << ": missing semicolon" << std::endl;
        }

        // Check for variable declaration
        size_t pos = line.find("int ");
        if (pos != std::string::npos)
        {
            size_t varStart = pos + 4;
            size_t varEnd = line.find_first_of(" =;", varStart);
            std::string varName = line.substr(varStart, varEnd - varStart);

            if (declaredVariables.find(varName) != declaredVariables.end())
            {
                std::cerr << "Semantic error on line " << lineNumber << ": redeclaration of variable " << varName << std::endl;
            }
            else
            {
                declaredVariables.insert(varName);
            }
        }

        // Check for variable usage
        for (const auto &var : declaredVariables)
        {
            if (line.find(var) != std::string::npos && line.find("int " + var) == std::string::npos)
            {
                std::cerr << "Semantic warning on line " << lineNumber << ": variable " << var << " used" << std::endl;
            }
        }
    }

    file.close();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    checkSyntax(argv[1]);

    return 0;
}
