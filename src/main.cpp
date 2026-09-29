#include <iostream>
#include <string>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Keep reading commands until the user enters the bare `exit` command.
  while (true){    
    // Show a prompt, then read one complete input line.
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    // This simple parser assumes a four-character command and a space before
    // its argument; it does not handle general shell quoting or tokenization.
    std::string argument = input.size() > 5 ? input.substr(5) : "";
    std::string command = input.substr(0, 4);

    // Bare `exit` ends the loop. Other builtin queries print a description.
    if (input == "exit") {
      break;
    } else if (command == "exit")
    {
      std::cout << argument << " is a shell builtin" <<std::endl;
    }else if (argument == "echo")
    {
      std::cout << argument << " is a shell builtin" <<std::endl;
    }else if (argument == "type")
    {
      std::cout << argument << " is a shell builtin" <<std::endl;
    }else if (command == "type" && (argument == "echo" || argument == "type" || argument == "exit"))
    {
      std::cout << argument << " is a shell builtin" << std::endl;
    }
    
    // `echo` prints everything after the command and its separating space.
    else if (input.substr(0, 5) == "echo "){
      std::cout << input.substr(5) << std::endl;
    } else {
    // For an unknown `type` target, report the target alone; otherwise report
    // the original command line as not found.
    std::cout << (command == "type" && !argument.empty() ? argument : input) << ": not found" << std::endl;
    }
  }
}
