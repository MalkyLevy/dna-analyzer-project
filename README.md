# DNA Analyzer Project
​
## Goal
​
The goal of the system is to load, analyze, manipulate and save DNA sequences.
​
## Description
​
DNA sequences are composed of four types of nucleotides; 
The nucleotides are marked A (Adenine), G (Guanine), C (Cytosine) and T (Thymine).
A full DNA molecule usually consists of two strands, connected to each other in base-pair connections: As with Ts, and Cs with Gs. 
Three successive nucleotides generate a codon, which might be chemically "read" in various ways.
​
The system will interact with the user through a CLI (Command Line Interface) that uses the standard I/O. Using that interface, the user will be able to load DNA sequences from files, to analyze them, to manipulate them (e.g., by extracting sequence slices or by modifying the sequence), and to store modified sequences and reports.
​
## Getting Started
​
The Command Line Interface (CLI)
The command line interface allows interaction with the user. Throughout that interface, the user can enter their input and see the application's output. The prompt of the CLI is usually > cmd >>>; it might change when special type of input is required.
​
Sequences
The application's most important elements are sequences. These are DNA sequences (composed of the four characters A, C, T and G). Each sequence that is held in the app's memory has a name and sequence number. When referring to a sequence in commands, unless otherwise defined, it is possible to refer it either by its ID or by its name.
​
Reference to the sequence number is done using the hash character # 
For example:
#1 means sequence number 1 .
#107 means sequence number 107.
​
Reference to the sequence name is done using the at character @ 
For example:
@short-seq refers to the sequence named short-seq.
@dolly-dna refers to the sequence named dolly-dna.
​
Files
The application stores and reads DNA sequences from files. It will use raw DNA data, that is, files that contain the four letters and nothing else.
​
Common CLI markings
```
[argument] - Words starting with "[", ending with "]" represent optional arguments.
<argument> - Words starting with "<", ending with ">" represent required arguments.
arg1|arg2 - Pipe sign ("|") between words represents that each one of them can be used.
```
avalable commands in this program:
```
> cmd >>> new <sequence> [@<sequence_name>]
> cmd >>> new ATACTGCCTGAATAC @short_seq
> cmd >>> load <file_name>  [@<sequence_name>]
> cmd >>> dup <seq> [@<new_seq_name>]
> cmd >>> slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]
> cmd >>> replace <seq> <index> <new_letter> [: [@<new_seq_name>|@@]]
> cmd >>> concat <seq_1> <seq_2> [: [@<new_seq_name>|@@]]
> cmd >>> pair <seq> [: [@<new_seq_name>|@@]]
> cmd >>> rename <seq> @<new_name>
> cmd >>> del <seq>
> cmd >>> reenum
> cmd >>> save <seq> [<filename>]
```
​
### Executing program
​
open cmd in your computer, enter the project folder by 'cd' command
compile and execute the program by the commands:
```
make all
./DNA
```
now you're ready to start,
first of all you have to load sequences to run the program on them by the command:
```
> cmd >>> load <file_name>  [@<sequence_name>]
```
now you can enter any of the avalable commands
enjoy!
​
## Help
​
```
run this command  for getting helper info:
> cmd >>> help [<command>]
```
