#include <iostream>
#include <string>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // TODO: Uncomment the code below to pass the first stage
  while (true){    
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    string argument = input.substr(5);
    string command = input.substr(0, 4);

    if (input == "exit") {
      break;
    } else if (command == "exit")
    {
      std::cout << argument << "is a shell builtin" <<std::endl;
    }else if (argument == "echo")
    {
      std::cout << argument << "is a shell builtin" <<std::endl;
    }else if (argument == "type")
    {
      std::cout << argument << "is a shell builtin" <<std::endl;
    }else if (command == "type" && command == "echo", && command =="exit")
    {
      
    }
    
     
    else if (input.substr(0, 5) == "echo "){
      std::cout << input.substr(5) << std::endl;
    } else {
    std::cout << input << ": command not found" << std::endl;
    }
  }
}
