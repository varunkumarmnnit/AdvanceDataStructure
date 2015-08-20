# AdvanceDataStructure

#### DESCRIPTION:- 

The   Project   is   divided   into   two   parts.In   Part   1   of   project   we   need   to  
implement   ​Dijkstra   Single   source   shortest   algorithm   using   a   Fibonacci.In  
Part   2   of   the   project   we   need   to   implement   a   routing   scheme   (routing)   for  
a   network   .The   data   structure   to   be   used   for   implementing   Part   2   is   Binary  
Trie   and   also   Dijkstra   algorithm   that   was   being   implemented   in   Part1   was  
also used . The   benefit   of   using   Fibonacci   Heap   for   Dijkstra   is   that   the   complexity   of  
algorithm   is   O   (E+VlogV)   time   where   E   is   number   of   edges   in   the   graph  
which   is   better   as   compared   to   using   other   data   structures   like   simple  
heap or array

#### Compilation Steps:- 
 ​
This project have been implemented in C++ and   compiled in Linux 
(Ubuntu) operating system with g++ compiler 
Following steps need to be followed to compile and execute the program.  
a)   Copy   all   the   files   mentioned   in   zip   folder   including   the   makefile   in   a  
separate directory  
b)  Run “​make clean​” to remove all previous output/executable files.  
c)   Run   “​make​”   .   This   will   generate   two   executables.  
ssp(Part   1)   and  routing(Part 2).  
d)The two executables generated should be executed in the following way 

***Part 1 Execution:*** 
 
 *./ssp ­­InputGraphFile ­­sourceVertex ­­destinationVertex*
 
* InputFileName   is   the   filename   which   contains   information   about   graph  
ie   source   vertex   ,destination   vertex   and   edge   weight   between   them.  
* sourceVertex is   the   source   vertex   from   where   the   shortest   path   to   be  
calculated.  
* destinationVertex   is   the   destination   vertex   upto   which   the   shortest   path  
is be calculated. 
 
***Part 2 Execution:***
 
 *./routing  ­­­InputGraphFile ­­InputIpFile ­­sourceVertex  ­­destinationVertex*
* InputFileName​  is same as above.  
* InputIpFile  ​ This file contains the IP address of each vertex.  
* sourceVertex ​ is same as above.  
* destinationVertex​  is same as above. 
