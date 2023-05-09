#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	openlog("writer", LOG_PID, LOG_USER);//syslog init
	
	//判断输入参数是否符合格式
	if (argc != 3){//命令行会把可执行文件当成第一个参数，所以加上字符串和文件名需要三个输入参数
		//printf("ERROR: incorrect input format. Usage: ./writer <string> <filename>");
		syslog(LOG_ERR, "ERROR: incorrect input format. Usage: ./writer <file path and name> <string>");
		closelog();
		return 1;}

	//printf("pass1");
	
	//传递输入
	char *file_path_name = argv[1];
	const char *string_content = argv[2];
	
	//printf("pass2");
	
	//打开文件并判断
	FILE *file_be_written=NULL;
	file_be_written = fopen(file_path_name, "w");
	if (file_be_written == NULL){
		//printf("%d\n",errno);
		//printf("ERR %s\n",strerror(errno));
		syslog(LOG_ERR, "ERROR: %s\n",strerror(errno));
		//fclose(file_be_written);
		closelog();
		return 1;}
	
	int fputs_out=fputs(string_content,file_be_written);
	//printf("%d\n",fputs_out);
	//写入字符串并判断
	if (fputs_out==EOF){
		//printf("ERROR\n");
		syslog(LOG_ERR, "ERROR: %s\n",strerror(errno));
		fclose(file_be_written);
		return 1;}
	
	//printf("pass\n");
	//结束操作，关闭文件并打印
	fclose(file_be_written);	
	//printf("writing %s to %s\n",argv[1],argv[2]);
	syslog(LOG_DEBUG,"Writing %s to %s\n",argv[2],argv[1]);
	//for (int i = 0; i < argc; i++) {
		//printf("Argument %d: %s\n", i, argv[i]);}
	return 0;}
