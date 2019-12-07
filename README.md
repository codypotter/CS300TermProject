# The ChocAn Simulator
## Usage Instructions
Run ChocAn.exe on windows or ./ChocAn on *nix to start the terminal simulator. 
From there you can simulate the manager or provider terminals, following the on-screen prompts.
Reports will be generated in the reports directory, and new members will be added to the database in the data directory.
## Build instructions
### Windows
1. Open a developer command prompt
2. navigate to the project root
3. `make`
4. Run ChocAn.exe

a.out will be generated in the build directory
### *nix
1. navigate to the project root
```
$ g++ *.cpp libs/*.cpp -Iinclude -oChocAn
```
CS300TermProject will be generated in the current directory
