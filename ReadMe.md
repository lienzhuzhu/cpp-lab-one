
# Author: Lien Zhu

# CSE 332 Lab 1 - Basic C++ Program Structure and Data Movement

This program reads in an input file specified by the user from command line and:
1. parses the content of the file by whitespace
2. separates the parsed strings into those that are and those that are not numeric values
3. prints the strings each on their own line, with those that are not numeric values printed before those that are numeric values

Note: numeric values preceded by only the '-' character are handled as negative numeric values


Possible program return values:
Enums for these can be found in enums.h
0 - successful program execution
    Should see parsed and differentiated strings output

1 - file_could_not_be_opened   
    Something went wrong trying to open the file 
    Please check to ensure the file specified exists in the correct path and is spelled correctly in command line
    
2 - wrong_number_of_arguments
    Please check to ensure a file name was provided and only one file is specified


Bugs and Learning:

After deciding on how many arguments would be passed through command line (total of 2) and how many 
error messages to have (3, including success), I tried running the program 
but got errorlevel 1, indicating the file could not be opened.

Figured out that input_file.txt has to be in same folder as application file, not source file after reading Studio 4 Enrichment.


I found that "strings" was being printed twice and figured out that if I extract the first string before checking 
if the ifs extraction operator could still extract another string:

    if (ifs.is_open()) { 

        // this

        string w;
        ifs >> w;

        while (ifs) {
            v_ref.push_back(w);
            ifs >> w;
        }

        // instead of this    
        while (ifs) {
            ifs >> w;
            v_ref.push_back(w);
        }
    }


Testing:

>lien-lab1.exe input_file.txt
these
all
are
strings
7string
str4ing
string2
more
strings
0
1
2
3
5
7
11
13
17
19
// Correct, consistent output, echo %errorlevel% returns 0 which is correct (success maps to 0)

>lien-lab1.exe input_file.tx
// Nothing, program terminates. echo %errorlevel% returns 1 which is correct (file_could_not_be_opened)

>lien-lab1.exe two arguments
usage: lien-lab1.exe input_file.txt
// Correct output, echo %errorlevel% returns 2 which is correct (wrong_number_of_arguments)

>lien-lab1.exe 
usage: lien-lab1.exe input_file.txt
// Correct output, echo %errorlevel% returns 2 which is correct (wrong_number_of_arguments)


------------
EXTRA CREDIT
------------

EC1
---

    [lienz@shell ~]$ ls
    332-labs  Downloads              etude.fasta  My Documents  Pictures  Templates  WINDOWS
    Desktop   Etude_DNAMaster.dnam5  Music        perl5         Public    Videos     winprofile
    [lienz@shell ~]$


EC2
---

    [lienz@shell ~]$ cd cse332/lab1/
    [lienz@shell lab1]$ make
    g++ -o lien-lab1.exe -DUNIX   -Wall -W -g -pedantic lien-lab1.cpp -lnsl
    lien-lab1.cpp: In function ‘int main(int, char**)’:
    lien-lab1.cpp:37:32: warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
             while (i < word.length()) {
                                    ^
    [lienz@shell lab1]$



    [lienz@shell ~]$ cd cse332/lab1/
    [lienz@shell lab1]$ ls
    enums.h  lien-lab1.cpp  lien-lab1.exe  Makefile  Templates.DB
    [lienz@shell lab1]$ touch input_file.txt
    [lienz@shell lab1]$ ls
    enums.h  input_file.txt  lien-lab1.cpp  lien-lab1.exe  Makefile  Templates.DB
    [lienz@shell lab1]$ input_
    bash: input_: command not found...
    [lienz@shell lab1]$ open input_file.txt
    Couldn't get a file descriptor referring to the console
    [lienz@shell lab1]$ input_file.txt
    bash: input_file.txt: command not found...
    [lienz@shell lab1]$ cat input_file.txt
    [lienz@shell lab1]$ echo 'test string' >> input_file.txt
    [lienz@shell lab1]$ cat input_file.txt
    test string
    [lienz@shell lab1]$ echo '1 2 3 4 10' >> input_file.txt
    [lienz@shell lab1]$ cat input_file.txt
    test string
    1 2 3 4 10
    [lienz@shell lab1]$ echo ' ' >> input_file.txt
    [lienz@shell lab1]$ cat input_file.txt
    test string
    1 2 3 4 10

    [lienz@shell lab1]$ echo '    str1ng  5 ' >> input_file.txt
    [lienz@shell lab1]$ cat input_file.txt
    test string
    1 2 3 4 10

        str1ng  5
    [lienz@shell lab1]$ ./lien-lab1.exe input_file.txt
    test
    string
    str1ng
    1
    2
    3
    4
    10
    5
    [lienz@shell lab1]$
