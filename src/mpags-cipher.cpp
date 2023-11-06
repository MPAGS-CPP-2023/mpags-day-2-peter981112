#include "transformChar.cpp"
#include "processCommandLine.cpp"
#include "RunCaesarCipher.cpp"

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it
    int number_of_lines{0};
    processCommandLine(cmdLineArgs,  helpRequested, versionRequested, inputFile, outputFile, number_of_lines);

    // Handle help, if requested
    if(helpRequested) 
    {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) 
    {
        std::cout << "version : 0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};

    std::string line;
    std::ifstream myfile (inputFile);
    std::cout<<number_of_lines<<" lines of txt from "<<inputFile<<std::endl;
    std::string inputText[number_of_lines];
    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {
        //std::cerr << "[warning] input from file ('" << inputFile<< "') not implemented yet, using stdin\n";
        int i{0};
        while (std::getline(myfile,line))
        {
            inputText[i] = line;
            std::cout << inputText[i] << '\n';
            i++;
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
    std::size_t key;
    char y_or_n;
    bool encrypt;
    std::cout<<"type key : ";
    std::cin>>key;
    std::cout<<std::endl;
    while(true)
    {
        std::cout<<"To encrypt type y, to decrypt type n : ";
        std::cin>>y_or_n;
        std::cout<<std::endl;
        if(y_or_n == 'y')
        {
            encrypt = true;
            break;
        }
        else if(y_or_n == 'n')
        {
            encrypt = false;
            break;
        }
        else
        {
            std::cout<<"no option for that please try again"<<std::endl;
        }
    }
    // loop over each character from input file

    std::string conv_str{""};
    std::ofstream out_text_file;
    out_text_file.open(outputFile);

    for(int i=0; i<number_of_lines; ++i)
    {
        for(int j=0; j<inputText[i].size(); j++)
        {
            conv_str = conv_str+RunCaesarCipher(transformChar(inputText[i][j]), key, encrypt);
        }
        out_text_file << conv_str+'\n';// encrypt line by line
        conv_str = "";
    }
    out_text_file.close();
    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}