## C++ in VS Code in a Linux Dev Container

### Code Formatting
Apply the coding standards via:
* Windows: ```SHIFT + ALT + F```
* Mac: ```SHIFT + OPTION + F```
* Linux: ```CTRL + SHIFT + I```


## Create and run GoogleTest

~~* From the terminal, type in the following command~~

~~git clone https://github.com/google/googletest.git~~

*We will standardize on a particular version of Google Test this semester:
```
wget https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz;
tar zxf v1.15.2.tar.gz;
mv googletest-1.15.2/ googletest;
rm v1.15.2.tar.gz;
```

* In the lower left of the Explorer window you will see Codespaces: and the name of your running codespace which is two words. At the far right you will see a triangle pointing right. Click that icon.
* You will be asked to select a Kit. Set the Kit to **Unspecified**. This only needs to be done once.
* Run unit tests from the command line:
   * At the command line:
   ```
   export CXX=`which clang++-16`;
   echo $CXX;
   cmake -S . -B ./build;
   cmake --build build --target clean;
   cmake --build build;
   ```
   * If you want to enable the debugger for the unit tests use:
   ```
   export CXX=`which clang++-16 -fstandalone-debug -g`
   ```
   * To run the test cases:
   ```
   build/test/TestsToRun
   ```

## Commands:
F5: Start Debugging (works)

Control-F5: Start without Debugging (works WINDOWS, not working MAC, output shows up in *DEBUG CONSOLE*)

[Not sure if *Start without Debugging* should work](https://github.com/microsoft/vscode-cpptools/issues/1201)

Control-Shift-B: Build (works)

Terminal | Run task | clean (works, calls *make clean*)

## Linux: 

Installs clang-16

* BUILD: WORKING
* DEBUG: WORKING
* If you want to use clang++ on linux make sure you have [libstdc++ installed correctly.](https://stackoverflow.com/a/66163184)
* gdb on Linux won't step into functions/run in functions [reliably](https://github.com/microsoft/vscode-cpptools/issues/3648)

## Notes
* [GDB to LLDB Command Mapping](https://lldb.llvm.org/use/map.html)
* [View pointer as array in debugger](https://github.com/microsoft/vscode-cpptools/issues/172#issuecomment-1281804128)
  *   For LLDB:
	  * `/nat *(int(*)[13])pIntArray`
  *   For GDB:
      * `*pIntArray@13` or  `*pIntArray@ARRAY_SIZE`
* [Using expressions in the watch panel with LLDB](https://github.com/vadimcn/vscode-lldb/blob/master/MANUAL.md#native-expressions)
* [lldb should debug gcc compiled code](https://aaronbloomfield.github.io/pdr/docs/gdb_vs_lldb.html)
* [vscode-cpptools](https://github.com/microsoft/vscode-cpptools#quick-links)
* [C++ on Windows](https://code.visualstudio.com/docs/cpp/config-msvc)
* [Using CLANG](https://code.visualstudio.com/docs/cpp/config-clang-mac)
* [Run Without Debugging](https://github.com/microsoft/vscode-cpptools/issues/1201)
* [Setup VS Code for C++ (iffy)](https://gourav.io/blog/setup-vscode-to-run-debug-c-cpp-code)
* [Debugging in VS Code](https://code.visualstudio.com/docs/editor/debugging)
* [Configuring Debugging](https://code.visualstudio.com/docs/cpp/launch-json-reference)
* [Launch.json schema](https://docs.microsoft.com/en-us/cpp/build/launch-vs-schema-reference-cpp?view=msvc-170)
* [tasks.json schema](https://code.visualstudio.com/docs/editor/tasks-appendix)
* [MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)
* [External tools and tasks](https://code.visualstudio.com/docs/editor/tasks)
* [C++20 in Visual Studio Compiler](https://devblogs.microsoft.com/cppblog/msvc-cpp20-and-the-std-cpp20-switch/)
* [Configure default terminal in VS Code](https://code.visualstudio.com/docs/terminal/profiles)
* [Working example of Configure default terminal in VS Code. Set args like in tasks.json to invoke VSDevCmd.bat](https://github.com/microsoft/vscode/issues/122355#issuecomment-833086902)
* [Print Extension](https://github.com/PDConSec/vsc-print/blob/master/doc/manual.eng.md)

## Git
* [Set local .gitconfig per directory](https://stackoverflow.com/questions/21307793/set-git-config-values-for-all-child-folders/48088291#48088291)
* [Use two GitHub accounts/SSH Keys on one computer](https://gist.github.com/aprilmintacpineda/f101bf5fd34f1e6664497cf4b9b9345f))

## [Key bindings](https://code.visualstudio.com/docs/getstarted/keybindings#_default-keybindings)

You can use key bindings to provide the not working Ctrl-F5 Start without Debugging feature:

keybindings.json:
```
  {
    "key": "Ctrl+F5",
    "command": "workbench.action.tasks.runTask",
    "args": "runMe",
    "when": "!inDebugMode"
  }
  ```
  
  Create a *runMe* task in *[tasks.json](.vscode/tasks.json#L72)* which calls the correct [Makefile](Makefile_linux#L29) to build and run the executable. 
  
  Note that keybindings are a *per user* setting, not a per project setting.
