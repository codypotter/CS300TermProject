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
<<<<<<< HEAD
4. Run ChocAn.exe
||||||| b2cf4f4
=======
4. `build\main.exe`
>>>>>>> c4ec2e1a79631c230342956ebc691cbce51eecd4

### *nix
1. navigate to the project root
```
<<<<<<< HEAD
$ g++ *.cpp libs/*.cpp -Iinclude -oChocAn
||||||| b2cf4f4
$ mkdir build && cd build
$ cmake ..
$ make
=======
$ mkdir build && cd build
$ cmake ..
$ make
$ ./CS300TermProject
>>>>>>> c4ec2e1a79631c230342956ebc691cbce51eecd4
```

