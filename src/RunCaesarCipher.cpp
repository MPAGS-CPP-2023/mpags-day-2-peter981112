#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


std::string RunCaesarCipher( const std::string& inputText, const std::size_t key, const bool encrypt)
{
    const std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    const size_t alphabet_size = alphabet.size();
    std::string out_text{""};
    
    char temp_char{'x'};
    std::size_t pos{0};
    std::size_t index;
    
    int len = inputText.size();
    for(int i=0; i<len; ++i)
    {
        temp_char = inputText[i];
        if(temp_char == ' ')
        {
            temp_char = ' ';
        }
        else
        {
            auto itr = std::find(alphabet.begin(), alphabet.end(), temp_char);
            index = std::distance(alphabet.begin(), itr);
            if(encrypt)
            {
                pos = (index+key)%alphabet_size;
            }
            else
            {
                pos = (index+alphabet_size-key)%alphabet_size;
            }
            temp_char = alphabet[pos];
        }
        out_text = out_text+temp_char;
    }
    return out_text;
}