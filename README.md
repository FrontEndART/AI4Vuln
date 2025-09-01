## AI4VULN
### Requirements

In order to build the AI4VULN executable the following tools are 
required:

- Linux
- CMake 3.22.0
- Compiler: clang 12
- JDK 11

### Checkout and build
After cloning the source code into an 
`ai4cyber` directory and creating a `Build` directory next to it, it can be 
built by executing the following commands in the `Build` directory:


    cmake ../ai4cyber -G "Unix Makefiles"
    make AI4VULN

In case of multiple (e.g. 8) processor cores it is faster to use:

    make -j8 AI4VULN

### Demo usage

Enter the `demo` directory and run the `analyze-dir.sh` script for an example analysis on the apache-log4j-1.2.17 project.
