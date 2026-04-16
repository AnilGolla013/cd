1)Download:
https://github.com/lexxmark/winflexbison/releases
win_flex_bison-*.zip



2)Extract the zip 

3)2. Add to PATH
Open Environment Variables
Go to Path → Edit → New
Add:
C:\winflexbison // extracted path


4)Open PowerShell:
Run:
win_flex --version
win_bison --version

▶️ Commands to run Lex file
win_flex file.l
gcc lex.yy.c -o output.exe
output.exe

▶️ Commands to run Lex + Yacc
win_bison -d file.y
win_flex file.l
gcc lex.yy.c file.tab.c -o output.exe
output.exe