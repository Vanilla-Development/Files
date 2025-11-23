How to make command line window hidden when building

Visual Studio:
1: Go to solution explorer
2: Right click on Project and goto "Properties"
3: Press Linker, then System
4: Where it says "SubSystem" replace "Console (/SUBSYSTEM:CONSOLE)" with "Windows (/SUBSYSTEM:WINDOWS)" to make command line window hidden

VS Code:
1 step:
Make sure to include "mwindows" in your command when you build if you use mingw/g++
