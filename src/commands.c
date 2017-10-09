#include <string.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;

  return chdir(argv[1]);
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char buf[255];
  getcwd(buf, 255);
  printf("%s\n", buf);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
	
	if(argc >= 1){
		if(strcmp(argv[0],"cd") != 0)
		return 0;
	}

 	if(argc == 1)
	return 0;

	else if(argc > 2)
	return 0;

	else
 	return 1;

}

int validate_pwd_argv(int argc, char** argv) {

  if(argc >= 1){
  	if(strcmp(argv[0],"pwd") != 0)
	return 0;
	}

  if(argc == 1){
 	return 1;
   }
   else{
	return 0;
   }
}
