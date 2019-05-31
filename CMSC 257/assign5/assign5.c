/*@ another attemp for shell
**@ Aplomb
** citation: stackoverflow.com/questions28502305/writhing-a-shell-in-c-using-fork-execvp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 1024

int main (int argc, char **argv)
{

  line[BUFFER_LEN];
  //argv[51];
  char *path = "/bin/";
  char progpath[20]; // program path
  char *str;

  if(argc > 2){str = *argv[2];}
  else{str = "257sh";}

 while (1)
 { printf("%s> ", str);//prints shell name
  
   if (!fgets(line, BUFFER_LEN, stdin)) //get command and put it in line
   { break;  } // if user hits CTRL+D break ??

   size_t length = strlen(line);

   if(line[length - 1] == '\n'){line[length - 1] = '\0';}
 
   if (strcmp(line, "exit") == 0){break;}// check if command is exit
   char *token; // split command into separate strings
   token = strtok(line, " ");//parsing 
   int i = 0;
   while(token != NULL)
   { argv[i]=token;
      token = strtok(NULL, " ");
     i++;
   }
   argv[i]=NULL; // set the last value to NULL for execvp

   argc = i; //get arg count
    
   for(i=0; i<argc; i++){printf("%s\n", argv[i]);}//prints the cmd/args

   strcpy(progpath, path);//copy /bin/ to file path
   strcat(progpath, argv[0]); // add program to path

   for(i=0; i<strlen(progpath); i++)//delete newline
   {
     if(progpath[i]=='\n'){progpath[i]= '\0';}
   }


  int pid = fork(); //fork child
  
  if(pid == 0) //child
  {
    execvp(progpath, argv); //runs a new program and does path processing
    fprintf(stderr, "Child process could not do execvp \n");
  }
  else{wait(NULL); printf("Child exited \n");} // parent waits for child
 
 //exit(); // exit the shell
//getpid(); //find the current process ID
//getppid(); // find the parent ID
//getcwd();//getting current working directory
//getenv();//getting environment
//setenv(); // setting environment
//chdir(); // changing directories
 //waitpid(); // wait for a child process to teminate

 }
return 0;}
