#include "Cmmand.h"

void selectCmmand(int msg_command,chatMssage *chat,char*sockWriteBuf,char *user)//ID 为当前用户的编号
{
    switch(msg_command)
    {
        case LOGIN:;break;
        case REGISTER:;break;
        case SEND:processsend(sockWriteBuf,chat);break;
        case LOOK:processLOOK(sockWriteBuf,user,chat);break;
        case LOOKBEFORE:break;
		case ANSEWER:processAnswer(sockWriteBuf,chat);break;
    }
}

void processAnswer(char*sockWriteBuf,chatMssage *chat)
{	
//	printf("ANSWER SUCCESSFULL");//在终端上打印接收成功啦。
	memset(sockWriteBuf,0,80);  //往发送的数据刷入数据。
	sprintf(sockWriteBuf,"$@17$%s$%s$ok$@$",chat->chat_receiveName,chat->chat_sendName);
//	printf(" senddata = %s \n",sockWriteBuf);
}

void processLOOK(char*sockWriteBuf,char *user,chatMssage *chat)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	memset(sockWriteBuf,0,80);  //往发送的数据刷入数据。
	sprintf(sockWriteBuf,"$@17$%s$%s$ok$@$",chat->chat_receiveName,chat->chat_sendName);
//	printf(" senddata = %s \n",sockWriteBuf);
	//printChat(*chat);
	init2arrar(user,100);//千万要注意这里的指针
//	printf("chat_message is %s\n",chat->chat_message);
	while (chat->chat_message[i] != '\0')
	{
	   if (chat->chat_message[i] == '\n')
	   {	
	   		k++;
	   		j = 0;
	   }else
	   {
	        user[k*10+j] = chat->chat_message[i];
	   		j++;
	   }
	   
	   i++;
//	   printf("i = %d ",i);
		
	}
	print2arrar(user);
}
// 注意这里是特殊问题特殊对待。是对10X10的二维数组进行处理
void init2arrar(char *user,int size)
{
	int i ;
	for(i = 0;i < size;i++)
		user[i] = 0;

	//printf("init2arrar is sucessful\n");

}
//同样这里问题还是同上内容
void print2arrar(char *user)
{
	int i = 0;
	char *p = user;
	i=1;
	while (strlen(p)!= 0)
	{
		printf("%d.%s\n",i,p);
		p  = &user[i*10];
		i++;
	}
	//printf("print sucess\n");

}
//处理send发送过来的数据,注意msg 大小制定是80
void processsend(char*msg,chatMssage *chat)
{
	//printf("receive %s data is %s \n",chat->chat_sendName,chat->chat_message);
	memset(msg,0,80);
	sprintf(msg,"%s : %s",chat->chat_sendName,chat->chat_message);
	//printf("%s\n",msg);
}
