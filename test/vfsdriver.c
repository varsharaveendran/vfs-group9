/*
 * File: vfsdriver.c
 *
 * Description: This is a driver program for testing your VFS system using an interaction script as input
 * You need to make additional calls to your respective functions as noted in the comments below
 * Make sure the output you display is exactly as per the given specifications for you. Do NOT print
 * any extra output (like debug messages) in the final version of your driver program. You can use this driver program
 * in a in incremental manner as you keep implementing one operator after another. For operators not yet implemented,
 * you can leave the output as given ("TO_BE_DONE"). So you can use this program as your "main" program for testing purposes.
 *
 * DO NOT write the full code for operators in the driver program! You must only CALL your functions from here.
 *
 * Usage: vfsdriver <scriptfilename>
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/MainHeaderFile.h"
#include"../include/NaryTreeFile.h"

#define BUFSIZE 200
#define CMDSIZE 30
#define PARSIZE 100
FILE *fp;


void createvfs ( char *P1, int P2 );
void mountvfs ( char *P1 );
void unmountvfs ( char *P1 );
void makedir ( char *P1, char *P2 );
void deletedir ( char *P1 );
void movedir ( char *P1, char *P2 );
void listdir ( char *P1, int P2, char *P3 );
void addfile ( char *P1, char *P2, char *P3 );
void listfile ( char *P1, char *P2 );
void updatefile ( char *P1, char *P2 );
void removefile ( char *P1 );
void movefile ( char *P1, char *P2 );
void copyfile ( char *P1, char *P2 );
void exportfile ( char *P1, char *P2 );
void searchfile ( char *P1, char *P2 );

void processcommand( char *command, char *P1, char *P2, char *P3 );

int main( int argc, char *argv[] )
{
	FILE *scriptfp;
	char linebuffer[BUFSIZE];
	char command[CMDSIZE], par1[PARSIZE], par2[PARSIZE], par3[PARSIZE];
	char *token;
//	fp = fopen("demo_interaction_output.txt","a");
	//fclose(fp);
	if( argc != 2 ){
		fprintf(stderr,"Usage: vfsdriver <scriptfile>\n");
		return(1);
	}

	if( (scriptfp=fopen(argv[1],"r")) == NULL ){
		fprintf(stderr,"Unable to open script file: %s\n", argv[1]);
		return(2);
	}
	
	while( fgets(linebuffer, sizeof(linebuffer), scriptfp) != NULL ){
		/* This output is for debugging... do not uncomment in final version */
		/*
		printf("==================================================\n");
		printf("Processing: %s", linebuffer);
		printf("==================================================\n");
		*/

		/* Remove the extra newline character in the end of line */
		linebuffer[ strlen(linebuffer)-1 ] = '\0';
		
		/* Get the command and the parameters using tokenizer */
		strcpy( command, (token = strtok(linebuffer, " ")) == NULL ? "" : token );
		
		strcpy( par1, (token = strtok(NULL, " ")) == NULL ? "" : token );
		strcpy( par2, (token = strtok(NULL, " ")) == NULL ? "" : token );
		strcpy( par3, (token = strtok(NULL, " ")) == NULL ? "" : token );
		/* printf("Command:%s:p1:%s:p2:%s:p3:%s\n",command, par1, par2, par3); */

		processcommand( command, par1, par2, par3 );
			
	}
	
	
}

void processcommand( char *command, char *P1, char *P2, char *P3 )
{

	
	if( strcmp(command, "createvfs") == 0 ){
		int size = atoi(P2);
		createvfs (P1,size);
	}
	else if( strcmp(command, "mountvfs") == 0 )
		mountvfs (P1);
	else if( strcmp(command, "unmountvfs") == 0 )
		unmountvfs (P1);
	else if( strcmp(command, "makedir") == 0 )
		makedir (P1,P2);
	else if( strcmp(command, "deletedir") == 0 )
		deletedir (P1);
	else if( strcmp(command, "movedir") == 0 )
		movedir (P1,P2);
	else if( strcmp(command, "listdir") == 0 ){
		int flag = atoi(P2);
		listdir (P1,flag,P3);
	}
	else if( strcmp(command, "addfile") == 0 )
		addfile (P1,P2,P3);
	else if( strcmp(command, "listfile") == 0 )
		listfile (P1,P2);
	else if( strcmp(command, "updatefile") == 0 )
		updatefile (P1,P2);
	else if( strcmp(command, "removefile") == 0 )
		removefile (P1);
	else if( strcmp(command, "movefile") == 0 )
		movefile (P1,P2);
	else if( strcmp(command, "copyfile") == 0 )
		copyfile (P1,P2);
	else if( strcmp(command, "exportfile") == 0 )
		exportfile (P1,P2);
	else if( strcmp(command, "searchfile") == 0 )
		searchfile (P1,P2);
	else
		printf("Ignoring invalid command %s\n", command);
}

void createvfs ( char *P1, int P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	
	//printf("createvfs_TO_BE_DONE\n");
	
	printf("%s\n",create_vfs(P1, P2));
}

void mountvfs ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
//	printf("mountvfs_TO_BE_DONE\n");
	printf("%s\n",mount(P1));
	
}

void unmountvfs ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	//printf("unmountvfs_TO_BE_DONE\n");
	
	int status = 0;
	status = unmount(P1);
	if(status)
		printf("unmountvfs_SUCCESS\n");
	else
		printf("unmountvfs_FAILURE Unmounting of VFS Failed\n");
	return;
}

void makedir ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
printf("calling mkdir .. n");
	char *status;
	//status = malloc(50*sizeof(char));
	
	//printf("P2 :%s\n",P2);
	status = make_dir(P1,P2);
	//fopen("demo_interaction_output.txt","a");
	printf("STATUS : %s\n", status);
	//while(strlen(status) > 0 )
	//fputs(status,fp);
	
//	free(status);
	return;
	
}

void deletedir ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	//printf("deletedir_TO_BE_DONE\n");
	char *status1;
	//status1 = malloc(50*sizeof(char));
	

	status1 = delete_dir(P1);
	
	printf("STATUS : %s\n", status1);
	//return;
}

void movedir ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	//printf("movedir_TO_BE_DONE\n");
	char * status;
	status = malloc(50*sizeof(char));
	status = move_dir(P1,P2);
	printf("STATUS : %s\n", status);
	
}

void listdir ( char *P1, int P2, char *P3 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	//printf("listdir_TO_BE_DONE\n");
	printf("%s  %d  %s\n" , P1 , P2 , P3);
	char *status;
	status = malloc(50*sizeof(char));
	
	status = list_dir(P1,P2,P3);
	printf("STATUS : %s\n",status);
	
	//free(status);
	//return;

	
}

void addfile ( char *P1, char *P2, char *P3 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	//printf("addfile_TO_BE_DONE\n");
	
	
	char *status;
	
	status = create_file(P1, P2, P3);
	
	printf("%s\n",status);
}

void listfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	printf("listfile_TO_BE_DONE\n");
}

void updatefile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	printf("updatefile_TO_BE_DONE\n");
}

void removefile ( char *P1 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	printf("removefile_TO_BE_DONE\n");
}

void movefile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	printf("movefile_TO_BE_DONE\n");
}

void copyfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
//	printf("copyfile_TO_BE_DONE\n");

	char * status;
	//status = malloc(50*sizeof(char));
	status = copy_file(P1,P2);
	printf("STATUS : %s\n", status);
	



}

void exportfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	printf("exportfile_TO_BE_DONE\n");
}

void searchfile ( char *P1, char *P2 )
{
	/* Call the appropriate function with given arguments and display appropriate output on the screen */
	printf("searchfile_TO_BE_DONE\n");
}

